//
// Created by Gianmarco Rossi on 01/07/23.
//

#ifndef CHESS_V2_BOARD_H
#define CHESS_V2_BOARD_H
#include "Piece.h"

class Board {
public:
    const uint64_t color_square_bitmask = 0xAAAAAAAAAAAAAAAA;
    Piece board[32];

    Board();

    friend std::ostream & operator<<(std::ostream &out, const Board &board);
    uint64_t occupiedSquare();


    ~Board();
};


#endif //CHESS_V2_BOARD_H
