cmake_minimum_required(VERSION 3.20.2)
project(Simple_Raytracer)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Ofast -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(Simple_Raytracer main.cpp color.h hittable.h sphere.cpp sphere.h hittable_list.cpp
        hittable_list.h rtweekend.h camera.h material.h ray.h vec3.h)
