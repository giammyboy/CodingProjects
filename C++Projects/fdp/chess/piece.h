//
// Created by Gianmarco Rossi on 04/05/23.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include <iostream>
#define B false
#define W true

class Piece {
public:
    [[nodiscard]] bool inCol(int newPos) const {
        if (this->pos % 8 == newPos % 8) return true;
        return false;
    }

    [[nodiscard]] bool inRow(int newPos) const {
        if (this->pos / 8 == newPos / 8) return true;
        return false;
    }

    [[nodiscard]] bool isNear(int newPos) const {
        if (inCol(newPos) && abs(row(pos) - row(newPos)) == 1 ||
            inRow(newPos) && abs(col(pos) - col(newPos)) == 1 ||
            (inEdge(newPos) &&
             abs(row(newPos) - row(pos)) == 1)) {
            return true;
        } else {
            return false;
        }
    }

    [[nodiscard]] bool inEdge(int newPos) const {
        if (abs(row(this->pos) - row(newPos)) == 1 &&
            abs(col(this->pos) - col(newPos)) == 1) {
            return true;
        } else {
            return false;
        }
    }

    [[nodiscard]] bool inDiagonal(int newPos) const {
        if (abs(row(this->pos) - row(newPos)) ==
            abs(col(this->pos) - col(newPos))) {
            return true;
        } else {
            return false;
        }
    }

    [[nodiscard]] bool inL(int newPos) const {
        if ((abs(col(pos) - col(newPos)) == 2 &&
             abs(row(pos) - row(newPos)) == 1) ||
            (abs(col(pos) - col(newPos)) == 1 &&
             abs(row(pos) - row(newPos)) == 2)) {
            return true;
        } else {
            return false;
        }
    }

    [[nodiscard]] bool notSame(int newPos) const {
        if (pos != newPos) return true;
        return false;
    }

    static int abs(int n) {
        if (n < 0) return -n;
        return n;
    }

    static int row(int pos) {
        return pos / 8;
    }

    static int col(int pos) {
        return pos % 8;
    }

    static bool inBoard(int pos) {
        if (pos >= 0 && pos <= 63) return true;
        return false;
    }

public:
    bool colour;
    int pos;
    char name;

    virtual bool getColour() { return this->colour; };
    virtual bool move(int newPos) = 0;
};

#endif //CHESS_PIECE_H
