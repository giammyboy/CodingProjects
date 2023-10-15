#include <iostream>
#include "dlist.h"

int main() {
    List l;
    l.append(10);
    l.append(20);
    l.append(30);
    l.append(40);
    l.show();
    l.pop();
    l.show();
    return 0;
}
