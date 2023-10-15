//
// Created by Gianmarco Rossi on 24/09/23.
//

#include "game.h"

Game::Game() : board{new Board{}}, rules{new Rules{}}, square_start{0},
                square_finish{0}, input_char{new char[INPUT_LENGHT]} {}

Game::~Game() {
    delete board;
    delete rules;
}

void Game::playMove(int index_start, int index_finish) const {
    if (rules->checkMove(board->game_board[index_start],
                         board->game_board[index_finish], board)) {
        board->movePiece(board->game_board[index_start], board->game_board[index_finish]);
    } else {
        std::cerr << "invalid move" << std::endl;
    }
}

void Game::forceMove(int index_start, int index_finish) const {
    board->movePiece(board->game_board[index_start], board->game_board[index_finish]);
}

void Game::display() const {
    std::wcout << *board << std::endl;
}

void Game::gameloop() {
    for (auto i = 0; i < 100; ++i) {

    }

}

void Game::start() {
}

int Game::getStartSquare(const char *input) {
}

int Game::getFinishSquare(const char *input) {

}

bool Game::checkInput(const std::string &input_string) {
    if (input_string.size() == 4) {
        for (auto i = 0; i <= 3; ++i) {
            if (i % 2 == 0) {
                if (input_string[i] >= 'a' && input_string[i] <= 'h') {
                    continue;
                } else {
                    throw std::invalid_argument("");
                }
            } else {

            }
        }
    }
}



void Game::getInput() {
    std::cin >> input;

}


