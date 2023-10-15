//
// Created by Gianmarco Rossi on 14/05/23.
//

#ifndef CHESS_V1_SQUARE_H
#define CHESS_V1_SQUARE_H

#include "set.h"

class Square {
public:
    int id;
    Piece * current;

    Square(int id, Piece *piece = nullptr) : id(id), current(piece) {
        updatePiecePos();
    }

    void updatePiecePos() const;
    bool isEmpty() const;
};


#endif //CHESS_V1_SQUARE_H
