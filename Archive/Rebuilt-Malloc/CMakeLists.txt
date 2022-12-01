cmake_minimum_required(VERSION 3.23)
project(Rebuilt_Malloc C)

set(CMAKE_C_STANDARD 23)

add_executable(Rebuilt_Malloc main.c allocator.c allocator.h)
