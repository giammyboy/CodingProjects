//
// Created by Gianmarco Rossi on 04/05/23.
//

#ifndef CHESS_SET_H
#define CHESS_SET_H

#include "piece.h"

class King : public Piece {
public:
    explicit King(bool colour, int _pos);
    bool move(int newPos) override;
};

class Queen : public Piece {
public:
    explicit Queen(bool colour, int _pos);
    bool move(int newPos) override;
};

class Bishop : public Piece {
public:
    explicit Bishop(bool colour, int _pos);
    bool move(int newPos) override;
};

class Rook : public Piece {
public:
    explicit Rook(bool colour, int _pos);
    bool move(int newPos) override;
};

class Knight : public Piece {
public:
    explicit Knight(bool colour, int _pos);
    bool move(int newPos) override;
};

class Pawn : public Piece {
public:
    explicit Pawn(bool colour, int _pos);
    bool move(int newPos) override;
};



#endif //CHESS_SET_H
