#include <iostream>
#include "museo.cpp"


int main() {
    museo m;
    IniazializzaMuseo(m, 1, 1);
    std::cout << m.mat[0] << std::endl;
    return 0;
}
