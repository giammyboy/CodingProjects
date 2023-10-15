cmake_minimum_required(VERSION 3.25)
project(chess_v1)

set(CMAKE_CXX_STANDARD 23)

add_executable(chess_v1 main.cpp piece.cpp piece.h square.cpp square.h set.cpp set.h)
