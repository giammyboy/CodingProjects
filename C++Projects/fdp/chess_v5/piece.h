//
// Created by Gianmarco Rossi on 23/09/23.
//

#ifndef CHESS_V5_PIECE_H
#define CHESS_V5_PIECE_H

#include "position.h"

class Piece {
public:
    enum class Type {
        king = U'K',
        queen = U'Q',
        rook = U'R',
        knight = U'N',
        bishop = U'B',
        pawn = U'P',
        empty = U'-' + 32
    };
    enum class Color {
        black = 0,
        white = 1,
        empty = -1
    };
    Type type;
    Color color;
    wchar_t char_to_display = ( wchar_t ) type + 32 * ( int ) color;

    Piece();

    Piece(Type set_type, Color set_color);

    [[nodiscard]] Piece::Color getColor() const;
    [[nodiscard]] Piece::Type getType() const;
    [[nodiscard]] wchar_t getChar() const;
    [[nodiscard]] bool isEmpty() const;
};


#include <iostream>
#endif //CHESS_V5_PIECE_H
