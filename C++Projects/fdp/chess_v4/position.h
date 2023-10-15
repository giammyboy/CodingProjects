//
// Created by Gianmarco Rossi on 27/07/23.
//

#ifndef CHESS_V4_POSITION_H
#define CHESS_V4_POSITION_H

#include "axis.h"

class File : public Axis {};
class Rank : public Axis {};

class Position {
    File file;
    Rank rank;
public:
    // Constructor
    Position(File set_file, Rank set_rank);

    // Setter for File and Rank
    void setFile(const File& new_file);
    void setRank(const Rank& new_rank);

    // Getter for File and Rank
    [[nodiscard]] File getFile() const;
    [[nodiscard]] Rank getRank() const;

    // Destructor
    ~Position();
};


#endif //CHESS_V4_POSITION_H
