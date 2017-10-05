cmake_minimum_required(VERSION 3.8)
project(ArbolB)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BloqueArbolB.cpp BloqueArbolB.h ArbolB.cpp ArbolB.h)
add_executable(ArbolB ${SOURCE_FILES})