cmake_minimum_required(VERSION 3.21)
project(Simple_Raytracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simple_Raytracer main.cpp vec3.h color.h ray.cpp ray.h hittable.h sphere.cpp sphere.h hittable_list.cpp
        hittable_list.h rtweekend.h camera.cpp camera.h)
