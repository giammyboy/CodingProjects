//
// Created by Gianmarco Rossi on 03/10/23.
//

#include "campo_minato.h"

Cell::Cell() : icon{'0'}, is_a_mine{false}, is_covered{true} {}

char Cell::getIcon() const {
    return icon;
}

bool Cell::isAMine() const {
    return is_a_mine;
}

bool Cell::isCovered() const {
    return is_covered;
}

void Cell::unveil() {
    is_covered = false;
}

void Cell::makeMine() {
    is_a_mine = true;
    icon = 'B';
}

void Cell::addMine() {
    ++icon;
}

bool Cell::isEmpty() const {
    return icon == '0' && !is_a_mine;
}

Cell::~Cell() = default;

Board::Board(int N) : is_game_started(false), is_game_startable{false}, is_game_lost{false}, is_game_won{false} {
    if (N  <= 0) {
        n = 3;
    } else {
        n = N;
    }

    board = new Cell*[n * n];

    for (auto i = 0; i < n * n; ++i) {
        board[i] = new Cell();
    }
}

Board::~Board() {
    delete[] board;
}

std::ostream &operator<<(std::ostream &os, const Board &b) {
    if (b.is_game_won) {
        os << "Vittoria!" << std::endl;
    } else if (b.is_game_lost) {
        os << "Game Over!" << std::endl;
    } else if (!b.is_game_startable) {
        os << "Inserisci una mina per avviare il gioco" << std::endl;
    } else {
        os << "   ";
        for (int k = 0; k < b.n; ++k) {
            os << k << "  ";
        }
        os << std::endl;
        for (int i = 0; i < b.n; ++i) {
            os << i << "  ";
            for (int j = 0; j < b.n; ++j) {
                if (b.board[i * b.n + j]->isCovered()) {
                    os << b.cover << "  ";
                } else {
                    if (b.board[i * b.n + j]->getIcon() == '0') {
                        os << "   ";
                    } else {
                        os << b.board[i * b.n + j]->getIcon() << "  ";
                    }
                }
            }
            os << std::endl;
        }
    }
    return os;
}

bool Board::addMine(int r, int c) {
    if (getIndex(r, c) != -1 && !is_game_started) {
        if (!board[getIndex(r, c)]->isAMine()) {
            board[getIndex(r, c)]->makeMine();
            updateBoard(r, c);
            is_game_startable = true;
        }
        return true;
    } else {
        return false;
    }
}

int Board::getIndex(int r, int c) const {
    if (r < n && r >= 0 && c < n && c >= 0) {
        return r * n + c;
    } else {
        return -1;
    }
}

void Board::discover(int r, int c) {
    if (is_game_startable && !is_game_lost) {
        int index = getIndex(r, c);
        if (index != -1) {
            is_game_started = true;
            board[index]->unveil();
            if (board[index]->isAMine()) {
                is_game_lost = true;
            }

        }
    }
    checkIfGameIsWon();
}

void Board::updateBoard(int r, int c) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (!(i == 0 && j == 0)) {
                if (getIndex(r + i, c + j) != -1) {
                    board[getIndex(r + i, c + j)]->addMine();
                }
            }
        }
    }
}

void Board::checkIfGameIsWon() {
    for (auto i = 0; i < n * n; ++i) {
        if (!board[i]->isAMine() && board[i]->isCovered()) {
            return;
        }
    }
    is_game_won = true;
}
