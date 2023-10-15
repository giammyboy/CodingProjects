#include <iostream>
#include "square.h"

int main() {
    King p('b');
    Square s(0, &p);
    std::cout << s.current->pos << std::endl;
    std::cout << s.current->isLegit(2) << std::endl;
    return 0;
}
