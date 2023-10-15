cmake_minimum_required(VERSION 3.25)
project(plot)
#include(FetchContent)


set(CMAKE_CXX_STANDARD 23)

find_package(Matplot++ REQUIRED)

add_executable(plot main.cpp
        pendolum.cpp
        pendolum.h)
target_link_libraries(plot PUBLIC Matplot++::matplot)
