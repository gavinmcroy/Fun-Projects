cmake_minimum_required(VERSION 3.21)
project(Simple_Raytracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simple_Raytracer main.cpp vec3.cpp vec3.h color.h ray.cpp ray.h)
