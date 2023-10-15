cmake_minimum_required(VERSION 3.25)
project(test)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)

find_package(Matplot++ REQUIRED)

add_executable(test main.cpp)
target_link_libraries(test PUBLIC Matplot++::matplot)
