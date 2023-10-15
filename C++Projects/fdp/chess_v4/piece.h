//
// Created by Gianmarco Rossi on 27/07/23.
//

#ifndef CHESS_V4_PIECE_H
#define CHESS_V4_PIECE_H

#include "position.h"

enum Color {B, W};

class Piece {
    Position square;
    Color color;

    virtual Position * possibleMoves() = 0;

public:
    // Constructor
    Piece(Position start_position, Color color);

    // Move the Piece
    void move(const Position& moving_to);

    // Check if the given Position is ok to move on
    virtual bool canMoveTo(Position moving_to) = 0;

    // Destructor
    ~Piece();

};


#endif //CHESS_V4_PIECE_H
