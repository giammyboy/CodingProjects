//
// Created by Gianmarco Rossi on 23/09/23.
//

#ifndef CHESS_V5_POSITION_H
#define CHESS_V5_POSITION_H

#include <iostream>

class Position {
    // Contain position
    // .file indicates the file (x-axis)
    // .rank indicates the rank (y-axis)

public:
    int file;
    int rank;
    Position() : file{-1}, rank{-1} {}
    Position(int set_file, int set_rank) : file{set_file}, rank{set_rank} {}

    bool operator==(const Position &other) const;
    bool operator!=(const Position &other) const;

    friend std::ostream& operator<<(std::ostream &os, const Position &postion);

    [[nodiscard]] int getFile() const;
    [[nodiscard]] int getRank() const;
    [[nodiscard]] int getIndex() const;

    bool isValid() const;
    void makeInvalid();
};


#endif //CHESS_V5_POSITION_H
