//
// Created by Gianmarco Rossi on 23/09/23.
//

#ifndef CHESS_V5_SQUARE_H
#define CHESS_V5_SQUARE_H

#include "piece.h"
#include "position.h"


class Square {
public:
    Piece *holding;
    const Position *position;

    Square();
    Square(Piece *to_hold, Position *set_position);
    Square(Piece *to_hold, Position &set_position);


    Piece* grabPiece();
    void putPiece(Piece *piece);
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] Piece::Color getColor() const;
    [[nodiscard]] Piece::Type getType() const;
    [[nodiscard]] const Position *getPosition() const;
    [[nodiscard]] wchar_t squareDisplay() const;

};


#endif //CHESS_V5_SQUARE_H
