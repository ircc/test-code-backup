﻿#struct、class、interface

##struct和class区别与联系

###关于使用大括号初始化
    class和struct如果定义了构造函数的话，都不能用大括号进行初始化
    如果没有定义构造函数，struct可以用大括号初始化。
    如果没有定义构造函数，且所有成员变量全是public的话，可以用大括号初始化。

###不同点

1. 默认访问权限：struct作为数据结构的实现体，它默认的数据访问控制是public的，而class作为对象的实现体，它默认的成员变量访问控制是private的

2. 默认继承方式访问权限： struct是public的，class是private的

3. "class"这个关键字还用于定义模板参数，就像"typename"。但关键字"struct"不用于定义模板参数

4. 还是上面所说的，C++中的struct是对C中的struct的扩充，既然是扩充，那么它就要兼容过去C中struct应有的所有特性

5. 在模版中，类型参数前面可以使用class或typename，如果使用struct，则含义不同，struct后面跟的是“non-type template parameter”，而class或typename后面跟的是类型参数



#虚析构函数
虚析构函数是为了当用一个基类的指针删除一个派生类的对象时，派生类的析构函数会被调用。

当然，并不是要把所有类的析构函数都写成虚函数。
因为当类里面有虚函数的时候，编译器会给类添加一个虚函数表，里面来存放虚函数指针，这样就会增加类的存储空间。
所以，只有当一个类被用来作为基类的时候，才把析构函数写成虚函数。

#继承的构造函数
##构造函数和析构函数的调用顺序
1、 儿子不能继承父亲的构造和析构函数
2、 执行顺序:
a) 创建父类的对象，构造函数的执行和子类没有关系。
b) 创建子类的对象，构造函数的执行顺序：
i. 首先执行父类的构造函数
ii. 再是成员对象所在类的构造函数
iii. 最后执行子类的构造函数
iv. 析构函数的执行顺序和构造函数相反

##子类构造函数的格式
1、 如果父类中只有无参的构造函数，子类不需要调用父类的构造函数。
2、 如果父类中有带参数的构造函数，子类必须要调用父类的构造函数，向父类传递参数。
3、 传递参数的格式：子类的构造函数：父类构造函数名(参数列表)
4、 一般子类的构造函数带参数的个数=继承下来的成员变量+子类自己成员变量。


