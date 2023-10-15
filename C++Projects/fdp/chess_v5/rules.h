//
// Created by Gianmarco Rossi on 24/09/23.
//

#ifndef CHESS_V5_RULES_H
#define CHESS_V5_RULES_H

#include "board.h"

class Rules {
    static constexpr int MAX_MOVES_LIST = 32;

    void cleanMoves() const;

    static bool isEatable(const Square *position_eater, const Square *square_eatable);
    static bool isEatable(const Position *position_eater, const Position *position_eatable, const Board *board);
    static bool isEnemy(const Position *position_eater, const Position *position_eatable, const Board *board);

    [[nodiscard]] bool checkMovesList(const Position *to_check) const;

    bool addMove(Position *position_to_add, const Board *board);

    void possibleMovesKing(const Square &self, const Board *board);

    void possibleMovesPawn(const Square &self, const Board *board);

    void possibleMovesRook(const Square &self, const Board *board);

    void possibleMovesBishop(const Square &self, const Board *board);

    void possibleMovesKnight(const Square &self, const Board *board);

    void possibleMovesQueen(const Square &self, const Board *board);


public:
    Position *moves;
    Position *move_p;
    const Square *current_square;

    Rules();
    ~Rules();

    bool checkMove(const Square *start, const Square *finish, const Board *board);
};

#endif //CHESS_V5_RULES_H
