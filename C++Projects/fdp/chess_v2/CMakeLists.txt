cmake_minimum_required(VERSION 3.25)
project(chess_v2)

set(CMAKE_CXX_STANDARD 23)

add_executable(chess_v2 main.cpp Piece.cpp Piece.h Board.cpp Board.h rules.cpp rules.h)
