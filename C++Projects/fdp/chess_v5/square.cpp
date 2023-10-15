//
// Created by Gianmarco Rossi on 23/09/23.
//

#include "square.h"

Square::Square() : holding{new Piece{}}, position{nullptr} {}

Square::Square(Piece *to_hold, Position *set_position) : holding{to_hold}, position{set_position} {}

Square::Square(Piece *to_hold, Position &set_position) : holding{to_hold}, position{&set_position} {}

Piece *Square::grabPiece() {
    if (holding->isEmpty()) {
        return new Piece{};
    } else {
        auto temp = holding;
        holding = new Piece{};
        return temp;
    }
}

void Square::putPiece(Piece *piece) { holding = piece; }

bool Square::isEmpty() const { return holding->isEmpty(); }

Piece::Color Square::getColor() const { return holding->getColor(); }

Piece::Type Square::getType() const { return holding->getType(); }

wchar_t Square::squareDisplay() const { return holding->getChar(); }

const Position *Square::getPosition() const {
    return position;
}

