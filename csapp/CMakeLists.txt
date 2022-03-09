cmake_minimum_required(VERSION 3.10)

project(csapp)

add_compile_options(-Wall -g -O2 -Werror -std=gnu99 -Wno-unused-function)

add_subdirectory(src)