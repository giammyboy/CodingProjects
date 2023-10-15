//
// Created by Gianmarco Rossi on 14/05/23.
//

#include "set.h"

King::King(char color) {
    this->color = color;
    this->name = 'K';
}

bool King::isLegit(const int &other) const {
    if (isNear(other) && inBoard(other) && notSame(other)) {
        return true;
    } else {
        return false;
    }
}

