#include "rules.h"

Rules::Rules() :moves{new Position[MAX_MOVES_LIST]}, move_p{moves}, current_square{nullptr} {}

Rules::~Rules() { delete[] moves; }


void Rules::cleanMoves() const {
    // Set all moves to Invalid state

    for (auto i = 0; i < MAX_MOVES_LIST; ++i) { moves[i].makeInvalid(); }
}

bool Rules::checkMove(const Square *start, const Square *finish, const Board *board) {
    // Check if is possible to do a move

    cleanMoves();

    current_square = start;

    // Assign the right kind of possible moves
    switch (start->getType()) {
        case Piece::Type::king:
            possibleMovesKing(*start, board);
        break;
        case Piece::Type::pawn:
            possibleMovesPawn(*start, board);
           break;
        case Piece::Type::rook:
            possibleMovesRook(*start, board);
            break;
        case Piece::Type::bishop:
            possibleMovesBishop(*start, board);
            break;
        case Piece::Type::knight:
            possibleMovesKnight(*start, board);
            break;
        case Piece::Type::queen:
            possibleMovesQueen(*start, board);
            break;
        default:
        std::cerr << "invalid type" << std::endl;
        break;
    }

    // debug
    for (auto move = moves; move < moves + MAX_MOVES_LIST; ++move) {
        if (move->isValid()) {
            std::clog << *move << std::endl;
        }
    }

    if (isEatable(start, finish) &&
    checkMovesList(finish->position) &&
    start->position != finish->position) {
        return true;
    } else {
        return false;
    }
}

bool Rules::isEatable(const Square *square_eater, const Square *square_eatable) {
    return square_eater->getColor() != square_eatable->getColor() || square_eatable->getColor() == Piece::Color::empty;
}

bool Rules::isEatable(const Position *position_eater, const Position *position_eatable, const Board *board) {
        auto game_board = board->game_board;
        return isEnemy(position_eater, position_eatable, board) || game_board[position_eatable->getIndex()]->isEmpty();
    }

bool Rules::isEnemy(const Position *position_eater, const Position *position_eatable, const Board *board) {
    auto game_board = board->game_board;
    return game_board[position_eater->getIndex()]->getColor() != game_board[position_eatable->getIndex()]->getColor() &&
           game_board[position_eatable->getIndex()]->getColor() != Piece::Color::empty;
}

bool Rules::checkMovesList(const Position *to_check) const {
        // Check if the move is in the possible moves
        for (Position * move = moves; move < moves + MAX_MOVES_LIST; ++move) {
            if (*to_check == *move) {
                return true;
            }
        }
        return false;
    }

bool Rules::addMove(Position *position_to_add, const Board *board) {
    if (position_to_add->isValid() && isEatable(current_square->getPosition(), position_to_add, board)) {
        *move_p = *position_to_add;
        ++move_p;
        return board->isSquareEmpty(position_to_add);
    } else {
        return false;
    }
}

void Rules::possibleMovesKing(const Square &self, const Board *board) {
    Position * move;
    for (auto file_axis = -1; file_axis <= 1; ++file_axis) {
        for (auto rank_axis = -1; rank_axis <= 1; ++rank_axis) {
            move = new Position(self.position->file + file_axis, self.position->rank + rank_axis);
            if (!addMove(move, board)) {
                break;
            }
        }
    }
}

void Rules::possibleMovesPawn(const Square &self, const Board *board) {
    Position *move;
    int add;
    if (self.holding->color == Piece::Color::white) {
        add = 1;
    } else {
        add = -1;
    }
    for (auto diagonal : {-1, 1}) {
        move = new Position{self.position->file + diagonal, self.position->rank + add};
        if (isEnemy(current_square->getPosition(), move, board)) {
            addMove(move, board);
        }
    }
    move = new Position{self.getPosition()->getFile(), self.getPosition()->getRank() + add};
    addMove(move, board);
}

void Rules::possibleMovesRook(const Square &self, const Board *board) {
    Position *move;
    // Checking right
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file + axis, self.position->rank};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking left
    for (auto axis = -1; axis >= -7; --axis) {
        move = new Position{self.position->file + axis, self.position->rank};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking up
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file, self.position->rank + axis};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking down
    for (auto axis = -1; axis >= -7; --axis) {
        move = new Position{self.position->file, self.position->rank + axis};
        if (!addMove(move, board)) {
            break;
        }
    }
}

void Rules::possibleMovesBishop(const Square &self, const Board *board) {
    Position *move;
    // Checking Up-Right
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file + axis,
                            self.position->rank + axis};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking Down-Right
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file + axis,
                            self.position->rank - axis};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking Up-Left
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file - axis,
                            self.position->rank + axis};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking Down-Left
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file - axis,
                            self.position->rank - axis};
        if (!addMove(move, board)) {
            break;
        }
    }
}

void Rules::possibleMovesKnight(const Square &self, const Board *board) {
    Position *move;
    for (auto direction : {1, -1}) {
        for (auto rank_variation : {1, -1}) {
            move = new Position(self.position->file + 2 * direction,
                                self.position->rank + rank_variation);
            if (!addMove(move, board)) {
                break;
            }
        }
    }
    for (auto direction : {1, -1}) {
        for (auto file_variation : {1, -1}) {
            move = new Position(self.position->file + file_variation,
                                self.position->rank + 2 * direction);
            if (!addMove(move, board)) {
                break;
            }
        }
    }
}

void Rules::possibleMovesQueen(const Square &self, const Board *board) {
    Position *move;
    // Checking right
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file + axis, self.position->rank};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking left
    for (auto axis = -1; axis >= -7; --axis) {
        move = new Position{self.position->file + axis, self.position->rank};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking up
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file, self.position->rank + axis};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking down
    for (auto axis = -1; axis >= -7; --axis) {
        move = new Position{self.position->file, self.position->rank + axis};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking Up-Right
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file + axis,
                            self.position->rank + axis};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking Down-Right
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file + axis,
                            self.position->rank - axis};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking Up-Left
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file - axis,
                            self.position->rank + axis};
        if (!addMove(move, board)) {
            break;
        }
    }
    // Checking Down-Left
    for (auto axis = 1; axis <= 7; ++axis) {
        move = new Position{self.position->file - axis,
                            self.position->rank - axis};
        if (!addMove(move, board)) {
            break;
        }
    }
}