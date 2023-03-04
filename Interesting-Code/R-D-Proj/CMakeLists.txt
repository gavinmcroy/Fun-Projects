cmake_minimum_required(VERSION 3.17)
project(MS2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(MS2
        a2ms2.c
        contactHelpers.c
        contactHelpers.h
        contacts.c
        contacts.h)
