//
// Created by Gianmarco Rossi on 01/07/23.
//

#include "Board.h"

std::ostream &operator<<(std::ostream &out, const Board &board) {
    char char_board[64];

    // initialize an empty board
    for (int i = 63; i >= 0; i--) {
        char_board[i] = ' ';
    }

    // fill the spot with the current pieces
    for (auto i : board.board) {
        char_board[i.getAbsolutePosition()] = i.getTypeChar();
    }

    // add the pieces to out
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            out << char_board[(rank * 8) + file] << "  ";
        }
        out << std::endl;
    }
    return out;
}

uint64_t Board::occupiedSquare() {
    uint64_t occupied_square_bitmask = 0;
    for (auto i : board) {
        if (i.storage == 0) {
            break;
        } else {
            occupied_square_bitmask |= (0b1 << i.getAbsolutePosition());
        }
    }
    return occupied_square_bitmask;
}

Board::Board() {
    // initialize position and color
    for (int i = 0; i < 32; i++) {
        if (i < 16) {
            this->board[i] = Piece(i % 8, i / 8, 0, 1);
        } else {
            this->board[i] = Piece(i % 8, i / 8 + 4, 0, 0);
        }
    }
    // initialize type
    this->board[0].setType(2);
    this->board[1].setType(3);
    this->board[2].setType(4);
    this->board[3].setType(5);
    this->board[4].setType(6);
    this->board[5].setType(4);
    this->board[6].setType(3);
    this->board[7].setType(2);
    this->board[8].setType(1);
    this->board[9].setType(1);
    this->board[10].setType(1);
    this->board[11].setType(1);
    this->board[12].setType(1);
    this->board[13].setType(1);
    this->board[14].setType(1);
    this->board[15].setType(1);
    this->board[16].setType(1);
    this->board[17].setType(1);
    this->board[18].setType(1);
    this->board[19].setType(1);
    this->board[20].setType(1);
    this->board[21].setType(1);
    this->board[22].setType(1);
    this->board[23].setType(1);
    this->board[24].setType(2);
    this->board[25].setType(3);
    this->board[26].setType(4);
    this->board[27].setType(5);
    this->board[28].setType(6);
    this->board[29].setType(4);
    this->board[30].setType(3);
    this->board[31].setType(2);
}

Board::~Board() = default;
