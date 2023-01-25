cmake_minimum_required(VERSION 3.17)
project(Project_4_Clion)

set(CMAKE_CXX_STANDARD 14)
#set(OpenGlLinkers  -framework GLUT -lobjc)

include_directories(.)

add_executable(Project_4_Clion
        graphics.cpp
        graphics.h
        Blur.cpp
        Blur.h
        main.cpp SeamCarving.cpp SeamCarving.h ImageObject.cpp ImageObject.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(Project_4_Clion ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
#target_link_libraries(Project_4_Clion ${OpenGlLinkers})
