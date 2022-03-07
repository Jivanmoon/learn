#PROJECT用来指定工程名字和支持的语言，默认支持所有语言
PROJECT(HELLO) #指定了工程的名字，并且支持所有的语言
#PROJECT(HELLO CXX) #指定了工程的名字，并且支持C++
#PROJECT(HELLO C CXX) #指定了工程的名字，并且支持C和C++
#该指定隐式定义了两个CMAKE的变量
#<project_name>_BINARY_DIR，本例中是 HELLO_BINARY_DIR
#<project_name>_SOURCE_DIR，本例中是 HELLO_SOURCE_DIR
# MESSAGE关键字就可以直接使⽤这两个变量，当前都指向当前的⼯作⽬录
# 问题：如果改了⼯程名，这两个变量名也会改变
# 解决：⼜定义两个预定义变量：PROJECT_BINARY_DIR和PROJECT_SOURCE_DIR，这两个变量和
# HELLO_BINARY_DIR，HELLO_SOURCE_DIR是⼀致的。所以改了⼯程名也没有关系


#SET关键字用来显示指定变量
#SET(SRC_LIST main.cpp) SRC_LIST变量就包含了main.cpp
SET(SRC_LIST main.cpp)


# MESSAGE关键字用来向终端输出用户自定义的信息
# 主要包含三种信息：
# SEND_ERROR，产⽣错误，⽣成过程被跳过。
# SATUS，输出前缀为“--”的信息。
# FATAL_ERROR，⽴即终⽌所有 cmake 过程.
MESSAGE(STATUS "This is BINARY dir" ${HELLO_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir" ${HELLO_SOURCE_DIR})


# ADD_EXECUTABLE用于生成可执行文件
# ADD_EXECUTABLE(hello ${SRC_LIST}) ⽣成的可执⾏⽂件名是hello，源⽂件读取变量SRC_LIST中的内容
# 也可以直接写 ADD_EXECUTABLE(hello main.cpp)
ADD_EXECUTABLE(hello ${SRC_LIST})

# 上述例⼦可以简化的写成
# PROJECT(HELLO)
# ADD_EXECUTABLE(hello main.cpp)
# 注意：⼯程名的 HELLO 和⽣成的可执⾏⽂件 hello 是没有任何关系的

