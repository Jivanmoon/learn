set(LIBHELLO_SRC hello.cpp)

# ADD_LIBRARY
# ADD_LIBRARY(hello SHARED ${LIBHELLO_SRC})

# hello：就是正常的库名，生成的名字前面会加上lib，最终产生的文件是libhello.so
# SHARED，动态库 
# STATIC，静态库
# ${LIBHELLO_SRC} ：源文件
add_library(hello SHARED ${LIBHELLO_SRC})