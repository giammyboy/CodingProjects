//
// Created by Gianmarco Rossi on 26/07/23.
//

#ifndef CHESS_V3_PIECE_H
#define CHESS_V3_PIECE_H

#include "Position.h"
#include "Move.h"

enum class Type {P, R, B, N, K, Q};

enum class Color {B, W};

class Piece {
Type type;
Position position;
Color color;

public:
    Piece(const Type& type, const Position& position, const Color& color);
};


#endif //CHESS_V3_PIECE_H
