//
// Created by Gianmarco Rossi on 04/05/23.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#define UP \033[A

#include "set.h"
#include "square.h"


class Board {
public:
    Square * board;
    Board();

    friend std::ostream& operator<<(std::ostream& os, const Board& b);
//    bool move(int newPos);
};


#endif //CHESS_BOARD_H
