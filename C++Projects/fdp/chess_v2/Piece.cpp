//
// Created by Gianmarco Rossi on 01/07/23.
//

#include "Piece.h"
#include "rules.h"
// Piece::storage is composed:
// 0b(fffrrr)FFFRRRTTTC R: ranks, F: files, T: type, C: color, r: prev rank, f: prev file
// color b = 1, color w = 0;

uint16_t  Piece::getFile() const {
    uint16_t file_bitmask = 0b0000001110000000;
    return (this->storage & file_bitmask) >> 7;
}

uint16_t  Piece::getRank() const {
    uint16_t rank_bitmask = 0b0000000001110000;
    return (this->storage & rank_bitmask) >> 4;
}

uint16_t  Piece::getType() const {
    uint16_t type_bitmask = 0b0000000000001110;
    return (this->storage & type_bitmask) >> 1;
}

uint16_t  Piece::getColor() const {
    uint16_t color_bitmask = 0b0000000000000001;
    return (this->storage & color_bitmask);
}

void Piece::setFile(int file) {
    if (file < 0|| file > 7) {
        std::cerr << "Invalid File" << std::endl;
        std::exit(1);
    } else {
        uint16_t current_file = this->getFile();
        uint16_t clear_prev_file_bitmask = 0b0001111111111111;
        uint16_t clear_file_bitmask = 0b1111110001111111;
        this->storage = (this->storage & clear_prev_file_bitmask) | (current_file << 13);
        this->storage = (this->storage & clear_file_bitmask) | (file << 7);
    }
}

void Piece::setRank(int rank) {
    if (rank < 0|| rank > 7) {
        std::cerr << "Invalid Rank" << std::endl;
        std::exit(1);
    } else {
        uint16_t current_rank = this->getRank();
        uint16_t clear_prev_rank_bitmask = 0b1110001111111111;
        uint16_t clear_rank_bitmask = 0b1111111110001111;
        this->storage = (this->storage & clear_prev_rank_bitmask) | (current_rank << 10);
        this->storage = (this->storage & clear_rank_bitmask) | (rank << 4);
    }
}

void Piece::setColor(int color) {
    if (color < 0|| color > 1) {
        std::cerr << "Invalid Color" << std::endl;
        std::exit(1);
    } else {
        uint16_t clear_color_bitmask = 0b1111111111111110;
        this->storage = (this->storage & clear_color_bitmask) | (color);
    }

}

void Piece::setType(int type) {
    if (type < 0|| type > 6) {
        std::cerr << "Invalid Type" << std::endl;
        std::exit(1);
    } else {
        uint16_t clear_type_bitmask = 0b1111111111110001;
        this->storage = (this->storage & clear_type_bitmask) | (type << 1);
    }
}

void Piece::setFile(char file) {
    if (file >= 'a' && file <= 'h') {
        file -= 'a';
        this->setFile((uint16_t) file);
    } else {
        std::cerr << "Invalid file" << std::endl;
        std::exit(1);
        // TODO: call again the the move function
    }
}

void Piece::setRank(char rank) {
    if (rank >= '1' && rank <= '8') {
        rank -= '1';
        this->setRank((uint16_t) rank);
    } else {
        std::cerr << "Invalid rank" << std::endl;
        std::exit(1);
        // TODO: call again the the move function
    }
}

void Piece::setType(char type) {
    switch (type) {
        case 'E':
            type = 0;
            break;
        case 'P':
            type = 1;
            break;
        case 'R':
            type = 2;
            break;
        case 'B':
            type = 3;
            break;
        case 'N':
            type = 4;
            break;
        case 'Q':
            type = 5;
            break;
        case 'K':
            type = 6;
            break;
        default:
            std::cerr << "Invalid Type" << std::endl;
            std::exit(1);
    }
    this->setType((uint16_t) type);
}

void Piece::setColor(char color) {
    if (color == 'b') {
        color = 0;
    } else if (color == 'w') {
        color = 1;
    } else {
        std::cerr << "Invalid Color" << std::endl;
        std::exit(1);
        // TODO: call again the function to set color
    }
    this->setColor((uint16_t) color);
}

uint16_t Piece::getAbsolutePosition() const {
    return this->getRank() * 8 + this->getFile();
}

char Piece::getTypeChar() const {
    return TYPE_CHAR[this->getType()];
}

Piece::Piece(int file, int rank, int type, int color) {
    this->storage = 0;
    this->setFile(file);
    this->setRank(rank);
    this->setType(type);
    this->setColor(color);
}

Piece::Piece() : storage(0) { }

bool Piece::checkMove(char *move) const {
    return false;
}

bool Piece::checkMove(int move) {
    if (move < 0 || move > 63) {
        return false;
    } else {
        switch (this->getType()) {
            case 1:
                return Rules::kingMove(this, move);
        }
    }
}

