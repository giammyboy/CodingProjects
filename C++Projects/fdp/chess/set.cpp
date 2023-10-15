//
// Created by Gianmarco Rossi on 04/05/23.
//

#include "set.h"
#include <iostream>

// King

King::King(bool colour, int _pos = 0) {
    this->colour = colour;
    this->name = "U+2654";
    this->pos = _pos;
}

bool King::move(const int newPos) {
    if (isNear(newPos) && inBoard(newPos) && notSame(newPos)) {
        this->pos = newPos;
        return true;
    } else {
        std::cerr << "Invalid Position" << std::endl;
        return false;
    }
}

// Queen

Queen::Queen(bool colour, int _pos = 0) {
    this->colour = colour;
    this->name = 'Q';
    this->pos = _pos;
}

bool Queen::move(const int newPos) {
    if ((isNear(newPos) ||
        inDiagonal(newPos) ||
        inRow(newPos) ||
        inCol(newPos)) &&
        inBoard(newPos) &&
        notSame(newPos)) {
        this->pos = newPos;
        return true;
    } else {
        std::cerr << "Invalid Position" << std::endl;
        return false;
    }
}

// Bishop

Bishop::Bishop(bool colour, int _pos = 0) {
    this->colour = colour;
    this->name = 'B';
    this->pos = _pos;
}

bool Bishop::move(const int newPos) {
    if (inDiagonal(newPos) && inBoard(newPos) && notSame(newPos)) {
        this->pos = newPos;
        return true;
    } else {
        std::cerr << "Invalid Position" << std::endl;
        return false;
    }
}

// Rook

Rook::Rook(bool colour, int _pos = 0) {
    this->colour = colour;
    this->name = 'R';
    this->pos = _pos;
}

bool Rook::move(const int newPos) {
    if (inRow(newPos) || inCol( newPos) && inBoard(newPos) && notSame(newPos)) {
        this->pos = newPos;
        return true;
    } else {
        std::cerr << "Invalid Position" << std::endl;
        return false;
    }
}

// Knight

Knight::Knight(bool colour, int _pos = 0) {
    this->colour = colour;
    this->name = 'N';
    this->pos = _pos;
}

bool Knight::move(const int newPos) {
    if (inL(newPos) && inBoard(newPos) && notSame(newPos)) {
        this->pos = newPos;
        return true;
    } else {
        std::cerr << "Invalid Position" << std::endl;
        return false;
    }
}

// Pawn

Pawn::Pawn(bool colour, int _pos = 0) {
    this->colour = colour;
    this->name = 'P';
    this->pos = _pos;
}

bool Pawn::move(const int newPos) {
    if (inCol(newPos) || inEdge( newPos) &&
        row(newPos) - row(pos) == 1 &&
        inBoard(newPos) && notSame(newPos)) {
        this->pos = newPos;
        return true;
    } else {
        std::cerr << "Invalid Position" << std::endl;
        return false;
    }
}

