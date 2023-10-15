#include <iostream>
#include "game.h"
#include <unistd.h>


using namespace std;

int main() {
    auto g = new Game{};
//    g->forceMove(8, 18);
    g->display();
    g->playMove(8, 16);
    g->display();
    g->playMove(0, 32);
    g->display();


    return 0;
}
