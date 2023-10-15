//
// Created by Gianmarco Rossi on 03/10/23.
//

#ifndef CAMPO_MINATO_CAMPO_MINATO_H
#define CAMPO_MINATO_CAMPO_MINATO_H

#include <iostream>

class Cell {
    char icon;
    bool is_a_mine;
    bool is_covered;

public:
    Cell();
    ~Cell();

    char getIcon() const;
    bool isAMine() const;
    bool isCovered() const;
    bool isEmpty() const;
    void unveil();
    void makeMine();
    void addMine();
};


class Board {

    int n;
    Cell **board = new Cell*[n * n];
    const char cover = 'X';
    bool is_game_started;
    bool is_game_startable;
    bool is_game_lost;
    bool is_game_won;

    int getIndex(int r, int c) const;
    void updateBoard(int r, int c);
    void checkIfGameIsWon();

public:

    Board(int N = 3);
    ~Board();

    friend std::ostream &operator<<(std::ostream &os, const Board &b);

    bool addMine(int r, int c);
    void discover(int r, int c);

};


#endif //CAMPO_MINATO_CAMPO_MINATO_H
