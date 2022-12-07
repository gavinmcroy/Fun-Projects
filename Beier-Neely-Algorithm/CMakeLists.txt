cmake_minimum_required(VERSION 3.22)
project(Beier_Neely_Algorithm)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenImageIO REQUIRED )
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${OpenImageIO_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIRS})

add_executable(Beier_Neely_Algorithm main.cpp LineSegment.cpp LineSegment.h)
target_link_libraries(Beier_Neely_Algorithm /usr/local/Cellar/openimageio/2.2.18.0/lib/libOpenImageIO.2.2.18.dylib)
target_link_libraries(Beier_Neely_Algorithm
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        )