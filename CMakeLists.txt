cmake_minimum_required(VERSION 3.0)
project(IVector)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
file(GLOB SRC src/*.cpp)

add_executable(IVector main.cpp)