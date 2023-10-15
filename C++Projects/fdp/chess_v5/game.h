//
// Created by Gianmarco Rossi on 24/09/23.
//

#ifndef CHESS_V5_GAME_H
#define CHESS_V5_GAME_H

#include "board.h"
#include "rules.h"

class Game {

    void clearInput();

    void getInput();
    bool checkInput(const std::string &input_string);

    static int getStartSquare(const char *input);
    static int getFinishSquare(const char *input);

public:
    static constexpr int INPUT_LENGHT = 4;

    Board *board;
    Rules *rules;
    int square_start;
    int square_finish;
    char *input_char;
    std::string input;

    void display() const;


    Game();
    ~Game();

    void forceMove(int index_start, int index_finish) const;
    void playMove(int index_start, int index_finish) const;

    void gameloop();
    void start();


};

#endif //CHESS_V5_GAME_H
