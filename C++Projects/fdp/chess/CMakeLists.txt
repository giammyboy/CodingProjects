cmake_minimum_required(VERSION 3.25)
project(chess)

set(CMAKE_CXX_STANDARD 23)

add_executable(chess main.cpp piece.cpp piece.h square.cpp square.h board.cpp board.h set.cpp set.h)
