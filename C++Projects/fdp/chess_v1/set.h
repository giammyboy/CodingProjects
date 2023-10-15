//
// Created by Gianmarco Rossi on 14/05/23.
//

#ifndef CHESS_V1_SET_H
#define CHESS_V1_SET_H

#include "piece.h"

class King : public Piece {
public:
    King(char color);

    [[nodiscard]] bool isLegit(const int &other) const override;


};


#endif //CHESS_V1_SET_H
