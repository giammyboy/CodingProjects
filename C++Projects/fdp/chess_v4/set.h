//
// Created by Gianmarco Rossi on 28/07/23.
//

#ifndef CHESS_V4_SET_H
#define CHESS_V4_SET_H

#include "piece.h"

class Pawn : public Piece {
    Position * possibleMoves() override;
public:
    bool canMoveTo(Position moving_to) override;
};


#endif //CHESS_V4_SET_H
