cmake_minimum_required(VERSION 3.15)
project(MultiProcessSync)

set(CMAKE_CXX_STANDARD 17)

add_executable(Parent src/parent.cpp)
add_executable(Child src/child.cpp)
