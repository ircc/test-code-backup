# 检查cmake的版本，至少为2.8
cmake_minimum_required(VERSION 2.8) 

# 工程名为 helloworld
project (helloworld)

# 设置变量的值
SET(SRC_LIST test.h test.cpp test_network.h test_network.cpp)

# 查找当前目录下所有的源文件并保存到SRC_LIST变量中
# aux_source_directory(.  SRC_LIST) 

# 查找库所在目录 找到的库全路径，包含库文件名
FIND_LIBRARY(PTHREAD_LIB pthread /usr/lib /usr/local/lib NO_DEFAULT_PATH)
FIND_LIBRARY(RUNTIME_LIB rt /usr/lib  /usr/local/lib NO_DEFAULT_PATH)


# 添加需要链接的库文件路径
link_libraries(${PTHREAD_LIB} ${RUNTIME_LIB} -lpthread -ldl)

# 添加编译选项
add_definitions(
-O3 -g -W -Wall
 -Wunused-variable -Wunused-parameter -Wunused-function -Wunused
 -Wno-deprecated -Woverloaded-virtual -Wwrite-strings
 -D__WUR= -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DTIXML_USE_STL
)

# 使用SRC_LIST源文件列表里的文件生成一个静态链接库 lib_test.a
add_library(lib_test STATIC ${SRC_LIST})  
# 动态链接库
#add_library(lib_test SHARD ${SRC_LIST})   

# 添加需要链接的库文件
link_libraries(lib_test)

# 使用源文件列表里的文件生成一个可执行文件 testd
add_executable(testd main.cpp)

# 使用SRC_LIST源文件列表里的文件生成一个可执行文件hello 注意变量使用需要加 ${SRC_LIST}
# add_executable(test  ${SRC_LIST}) 