#include <iostream>

#include "Position.h"

class Mother {
public:
    int i;
    int re;

    Mother() : i(0), re(0) {};

    bool canMove() {
        return true;
    }
};

class child1 : public Mother {
public:
    bool canMove() {
        return true;
    }
};

class child2 : public Mother {
public:
    bool canMove() {
        return false;
    }
};


int main() {
    auto a = new child1();
    auto b = new child2();
    Mother * array[2] = {a, b};
    std::cout << array[0].i << std::endl;
    return 0;
}
