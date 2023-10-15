//
// Created by Gianmarco Rossi on 23/09/23.
//

#ifndef CHESS_V5_BOARD_H
#define CHESS_V5_BOARD_H



#include "square.h"


class Board {

    static int getIndex(const Position *position);
    static int getIndex(const Square& square);


public:
    static constexpr int MAX_EATABLE_PIECES = 32;
    static constexpr int TOTAL_SQUARES = 64;

    Square **game_board = new Square*[TOTAL_SQUARES];
    Piece *eaten_pieces = new Piece[MAX_EATABLE_PIECES];

    Board();

    friend std::wostream& operator<<(std::wostream &os, const Board &board);

    void movePiece(Square *start, Square *finish);
    [[nodiscard]] bool isSquareEmpty(const Position *square_position) const;
    [[nodiscard]] Piece::Color getSquareColor(const Square &square) const;

    ~Board();
};


#endif //CHESS_V5_BOARD_H
