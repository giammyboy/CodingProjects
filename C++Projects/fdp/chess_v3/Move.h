//
// Created by Gianmarco Rossi on 26/07/23.
//

#ifndef CHESS_V3_MOVE_H
#define CHESS_V3_MOVE_H

#include "Position.h"

class Move {
Position start;
Position end;

public:
    Move(const Position& start, const Position& end);

    ~Move();
};


#endif //CHESS_V3_MOVE_H
