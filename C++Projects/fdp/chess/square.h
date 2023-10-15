//
// Created by Gianmarco Rossi on 04/05/23.
//

#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include "piece.h"


class Square {
public:
    int id;
    Piece * current;

    Square();
    explicit Square(int id);

    void setPiece(Piece * piece);
    [[nodiscard]] bool isEmpty() const;
};


#endif //CHESS_SQUARE_H
