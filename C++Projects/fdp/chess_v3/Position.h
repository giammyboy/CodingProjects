//
// Created by Gianmarco Rossi on 26/07/23.
//

#ifndef CHESS_V3_POSITION_H
#define CHESS_V3_POSITION_H

#include <iostream>

enum class Rank {a, b, c, d, e, f, g, h};
enum class File {a, b, c, d, e, f, g, h};

class Position {
File file;
Rank rank;

public:
    Position(File file, Rank rank);

    [[nodiscard]] File getFile() const;
    [[nodiscard]] Rank getRank() const;

    void setFile(File file_to_set);
    void setRank(Rank rank_to_set);

    ~Position();
};


#endif //CHESS_V3_POSITION_H
