cmake_minimum_required(VERSION 3.23)
project(RadixSorting)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RadixSorting
        header.h
        main.cpp
        queue.cpp
        radix.cpp
        IO.cpp)