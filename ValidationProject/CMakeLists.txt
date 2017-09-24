cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp GridCheck.cpp GridCheck.h)
add_executable(untitled ${SOURCE_FILES})