cmake_minimum_required(VERSION 3.17)
project(Clion_Test)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Clion_Test
        blur.cpp
        graphics.cpp
        graphics.h)
