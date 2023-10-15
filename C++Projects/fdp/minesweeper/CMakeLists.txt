cmake_minimum_required(VERSION 3.26)
project(minesweeper)

set(CMAKE_CXX_STANDARD 23)

add_executable(minesweeper main.cpp
        CampoMinato.cpp
        CampoMinato.h)
