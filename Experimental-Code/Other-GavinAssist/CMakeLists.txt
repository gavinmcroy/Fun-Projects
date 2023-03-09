cmake_minimum_required(VERSION 3.23)
project(Assist C)

set(CMAKE_C_STANDARD 99)

add_executable(Assist main.c utils.h utils.c)
