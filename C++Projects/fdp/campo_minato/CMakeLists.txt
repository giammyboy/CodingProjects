cmake_minimum_required(VERSION 3.26)
project(campo_minato)

set(CMAKE_CXX_STANDARD 23)

add_executable(campo_minato main.cpp
        campo_minato.cpp
        campo_minato.h)
