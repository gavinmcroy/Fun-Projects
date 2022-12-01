cmake_minimum_required(VERSION 3.17)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_1
        Utils.cpp StringIntMap.cpp StringIntMap.h StoredWebPages.cpp StoredWebPages.h StoredWords.cpp StoredWords.h)
