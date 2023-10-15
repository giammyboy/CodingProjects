cmake_minimum_required(VERSION 3.25)
project(chess_v3)

set(CMAKE_CXX_STANDARD 23)

add_executable(chess_v3 main.cpp Position.cpp Position.h Move.cpp Move.h Piece.cpp Piece.h)
