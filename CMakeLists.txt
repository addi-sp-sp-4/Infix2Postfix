cmake_minimum_required(VERSION 3.7)
project(infix_to_postfix)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp infix2postfix.cpp infix2postfix.h)
add_executable(infix_to_postfix ${SOURCE_FILES})