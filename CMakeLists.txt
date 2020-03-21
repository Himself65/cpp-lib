cmake_minimum_required(VERSION 3.15)
project(bread-lib)

set(CMAKE_CXX_STANDARD 20)

add_library(bread-lib src/library.cpp src/library.h)

add_subdirectory(tests)