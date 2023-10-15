//
// Created by Gianmarco Rossi on 27/07/23.
//

#include "position.h"

Position::Position(File set_file, Rank set_rank) : file(set_file), rank(set_rank) { }

void Position::setFile(const File& new_file) {
    this->file = new_file;
}

void Position::setRank(const Rank& new_rank) {
    this->rank = new_rank;
}

File Position::getFile() const {
    return this->file;
}

Rank Position::getRank() const {
    return this->rank;
}

Position::~Position() = default;
