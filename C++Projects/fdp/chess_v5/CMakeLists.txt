cmake_minimum_required(VERSION 3.26)
project(chess_v5)

set(CMAKE_CXX_STANDARD 20)

add_executable(chess_v5 main.cpp
        position.cpp
        position.h
        piece.cpp
        piece.h
        square.cpp
        square.h
        board.cpp
        board.h
        rules.cpp
        rules.h
        game.cpp
        game.h
)
