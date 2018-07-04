# 检查cmake的版本，至少为2.8
cmake_minimum_required(VERSION 2.8) 

# 工程名为 helloworld
project (helloworld)

# 设置变量的值
SET(SRC_LIST main.c)

# 查找当前目录下所有的源文件并保存到SRC_LIST变量中
# aux_source_directory(.  SRC_LIST) 

message(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})
message(STATUS "This is SOURCE dir "${HELLO_SOURCE_DIR})
#ADD_EXECUTABLE(hello main.c)

# 使用SRC_LIST源文件列表里的文件生成一个可执行文件hello 注意变量使用需要加 ${SRC_LIST}
add_executable(hello  ${SRC_LIST}) 