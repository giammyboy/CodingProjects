//
// Created by Gianmarco Rossi on 24/09/23.
//

#include "position.h"

bool Position::isValid() const {
    if (file >= 0 && file <= 7 && rank >= 0 && rank <= 7) {
        return true;
    } else {
        return false;
    }
}

void Position::makeInvalid() {
    file = -1;
    rank = -1;
}

bool Position::operator==(const Position &other) const {
    if (file == other.file && rank == other.rank) {
        return true;
    } else {
        return false;
    }
}

bool Position::operator!=(const Position &other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream &os, const Position &postion) {
    os << "(" << postion.file << ", " << postion.rank << ")";
    return os;
}

int Position::getFile() const { return file; }

int Position::getRank() const { return rank; }

int Position::getIndex() const { return file + rank * 8; }
