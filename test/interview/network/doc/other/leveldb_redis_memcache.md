#leveldb redis memcache mongodb

##LevelDB入门
https://www.zhihu.com/question/38933764
LevelDB是Google开源的持久化KV单机数据库，具有很高的随机写，顺序读/写性能，但是随机读的性能很一般，也就是说，LevelDB很适合应用在查询较少，而写很多的场景。LevelDB应用了LSM (Log Structured Merge) 策略，lsm_tree对索引变更进行延迟及批量处理，并通过一种类似于归并排序的方式高效地将更新迁移到磁盘，降低索引插入开销，关于LSM，本文在后面也会简单提及。

根据Leveldb官方网站的描述，LevelDB的特点和限制如下：

###特点：
1. key和value都是任意长度的字节数组；
2. entry（即一条K-V记录）默认是按照key的字典顺序存储的，当然开发者也可以重载这个排序函数；
3. 提供的基本操作接口：Put()、Delete()、Get()、Batch()；
4. 支持批量操作以原子操作进行；
5. 可以创建数据全景的snapshot(快照)，并允许在快照中查找数据；
6. 可以通过前向（或后向）迭代器遍历数据（迭代器会隐含的创建一个snapshot）；
7. 自动使用Snappy压缩数据；
8. 可移植性；

###限制：
1. 非关系型数据模型（NoSQL），不支持sql语句，也不支持索引；
2. 一次只允许一个进程访问一个特定的数据库；
3. 没有内置的C/S架构，但开发者可以使用LevelDB库自己封装一个server；

LevelDB本身只是一个lib库，在源码目录make编译即可，然后在我们的应用程序里面可以直接include leveldb/include/db.h头文件，该头文件有几个基本的数据库操作接口


##Redis 

Redis是一个开源的使用ANSI C语言编写、支持网络、可基于内存亦可持久化的日志型、Key-Value数据库，并提供多种语言的API。从2010年3月15日起，Redis的开发工作由VMware主持。从2013年5月开始，Redis的开发由Pivotal赞助。

###定义

redis是一个key-value存储系统。和Memcached类似，它支持存储的value类型相对更多，包括string(字符串)、list(链表)、set(集合)、zset(sorted set --有序集合)和hash（哈希类型）。这些数据类型都支持push/pop、add/remove及取交集并集和差集及更丰富的操作，而且这些操作都是原子性的。在此基础上，redis支持各种不同方式的排序。与memcached一样，为了保证效率，数据都是缓存在内存中。区别的是redis会周期性的把更新的数据写入磁盘或者把修改操作写入追加的记录文件，并且在此基础上实现了master-slave(主从)同步。

Redis 是一个高性能的key-value数据库。很大程度补偿了memcached这类key/value存储的不足，在部 分场合可以对关系数据库起到很好的补充作用。

Redis支持主从同步。数据可以从主服务器向任意数量的从服务器上同步，从服务器可以是关联其他从服务器的主服务器。这使得Redis可执行单层树复制。存盘可以有意无意的对数据进行写操作。由于完全实现了发布/订阅机制，使得从数据库在任何地方同步树时，可订阅一个频道并接收主服务器完整的消息发布记录。同步对读取操作的可扩展性和数据冗余很有帮助。

###数据模型

Redis的外围由一个键、值映射的字典构成。与其他非关系型数据库主要不同在于：Redis中值的类型[1]  不仅限于字符串，还支持如下抽象数据类型：

* 字符串列表
* 无序不重复的字符串集合
* 有序不重复的字符串集合
* 键、值都为字符串的哈希表[1] 

值的类型决定了值本身支持的操作。Redis支持不同无序、有序的列表，无序、有序的集合间的交集、并集等高级服务器端原子操作。


###数据结构

redis提供五种数据类型：string，hash，list，set及zset(sorted set)。



##Redis与Memcached的区别


如果简单地比较Redis与Memcached的区别，大多数都会得到以下观点：

1  Redis不仅仅支持简单的k/v类型的数据，同时还提供list，set，zset，hash等数据结构的存储。
2  Redis支持数据的备份，即master-slave模式的数据备份。
3  Redis支持数据的持久化，可以将内存中的数据保持在磁盘中，重启的时候可以再次加载进行使用。

抛开这些，可以深入到Redis内部构造去观察更加本质的区别，理解Redis的设计。

在Redis中，并不是所有的数据都一直存储在内存中的。这是和Memcached相比一个最大的区别。Redis只会缓存所有的 key的信息，如果Redis发现内存的使用量超过了某一个阀值，将触发swap的操作，Redis根据“swappability = age*log(size_in_memory)”计 算出哪些key对应的value需要swap到磁盘。然后再将这些key对应的value持久化到磁盘中，同时在内存中清除。这种特性使得Redis可以 保持超过其机器本身内存大小的数据。当然，机器本身的内存必须要能够保持所有的key，毕竟这些数据是不会进行swap操作的。同时由于Redis将内存 中的数据swap到磁盘中的时候，提供服务的主线程和进行swap操作的子线程会共享这部分内存，所以如果更新需要swap的数据，Redis将阻塞这个 操作，直到子线程完成swap操作后才可以进行修改。