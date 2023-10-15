//
// Created by Gianmarco Rossi on 14/05/23.
//

#include "square.h"

bool Square::isEmpty() const {
    return this->current == nullptr;
}

void Square::updatePiecePos() const {
    this->current->setPos(id);
}
