//
// Created by Gianmarco Rossi on 07/10/23.
//

#ifndef MINESWEEPER_CAMPOMINATO_H
#define MINESWEEPER_CAMPOMINATO_H


class Cell {
    char nearby_mines;
    bool is_a_mine;
    bool is_covered;
};


class MineSweeper {
    enum class States {startable, started, won, lost};

    int n;



};


#endif //MINESWEEPER_CAMPOMINATO_H
