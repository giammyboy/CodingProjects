//
// Created by Gianmarco Rossi on 23/09/23.
//

#include "piece.h"

Piece::Piece() : type{Type::empty}, color(Color::empty) {}

Piece::Piece(Piece::Type set_type, Piece::Color set_color) : type{set_type}, color{set_color} {}

bool Piece::isEmpty() const { return type == Type::empty && color == Color::empty; }

Piece::Color Piece::getColor() const { return this->color; }

Piece::Type Piece::getType() const { return this->type; }

wchar_t Piece::getChar() const { return char_to_display; }


