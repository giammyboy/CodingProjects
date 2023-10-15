//
// Created by Gianmarco Rossi on 27/07/23.
//

#include "piece.h"

Piece::Piece(Position start_position, Color color) : square(start_position), color(color) { }

void Piece::move(const Position& moving_to) {
    this->square = moving_to;
}

Piece::~Piece() = default;
