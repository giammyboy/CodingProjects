#include <iostream>

#include "campo_minato.h"


int main() {
    auto a = new Board(10);
    a->addMine(4, 4);
    a->discover(3, 4);
    std::cout << *a << std::endl;


    std::cout << *a << std::endl;

    return 0;
}
