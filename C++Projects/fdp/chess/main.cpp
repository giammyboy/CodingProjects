#include <iostream>
#include <unistd.h>
#include "set.h"
#include "square.h"
#include "board.h"
#define UP "\033[A"
#define BK "\r"

int main() {
    Board b;
    std::cout << b << std::endl;
    b.board[16].setPiece(new Pawn(W, 16));
    b.board[8].setPiece((nullptr));
    std::cout << b << std::endl;
}
