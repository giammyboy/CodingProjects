cmake_minimum_required(VERSION 3.25)
project(chess_v4)

set(CMAKE_CXX_STANDARD 23)

add_executable(chess_v4 main.cpp position.cpp position.h piece.cpp piece.h axis.cpp axis.h set.cpp set.h)
