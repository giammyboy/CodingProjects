//
// Created by Gianmarco Rossi on 26/07/23.
//

#include "Position.h"

Position::Position(File file, Rank rank) : file(file), rank(rank) { }

File Position::getFile() const {
    return this->file;
}

Rank Position::getRank() const {
    return this->rank;
}

void Position::setFile(File file_to_set) {
    this->file = file_to_set;
}

void Position::setRank(Rank rank_to_set) {
    this->rank = rank_to_set;
}

Position::~Position() = default;
