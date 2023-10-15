//
// Created by Gianmarco Rossi on 04/05/23.
//

#include <iostream>
#include "square.h"


Square::Square() : id(0) { }

Square::Square(int id) : id(id), current(nullptr) { }


void Square::setPiece(Piece *piece) {
    this->current = piece;
    if (this->current != nullptr) this->current->pos = this->id;
}

bool Square::isEmpty() const {
    if (this->current == nullptr) return true;
    return false;
}