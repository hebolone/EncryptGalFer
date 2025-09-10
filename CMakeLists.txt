cmake_minimum_required(VERSION 3.27)
project(MyProject CXX)

set (CMAKE_CXX_STANDARD 23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/)

add_executable(schoolie School.cpp)