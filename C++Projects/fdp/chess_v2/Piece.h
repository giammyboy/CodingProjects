//
// Created by Gianmarco Rossi on 01/07/23.
//

#ifndef CHESS_V2_PIECE_H
#define CHESS_V2_PIECE_H
#include <iostream>

class Piece {
public:
    // Piece::storage is composed:
    // 0b(fffrrr)FFFRRRTTTC R: ranks, F: files, T: type, C: color, r: prev rank, f: prev file
    // color b = 1, color w = 0;
    uint16_t storage;

    constexpr static const char TYPE_CHAR[7] = {'E', 'P', 'R', 'B', 'N', 'Q', 'K'};

    Piece();
    Piece(int file, int rank, int type, int color);

    [[nodiscard]] uint16_t getRank() const;
    [[nodiscard]] uint16_t  getFile() const;
    [[nodiscard]] uint16_t  getType() const;
    [[nodiscard]] uint16_t  getColor() const;
    [[nodiscard]] uint16_t getAbsolutePosition() const;
    [[nodiscard]] char getTypeChar()const;

    void setRank(char rank);
    void setRank(int rank);
    void setFile(char file);
    void setFile(int file);
    void setType(char type);
    void setType(int type);
    void setColor(char color);
    void setColor(int color);

    bool checkMove(char *move) const;
    [[nodiscard]] bool checkMove(int move);
};


#endif //CHESS_V2_PIECE_H
