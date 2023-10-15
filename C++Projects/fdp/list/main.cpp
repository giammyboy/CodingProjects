#include <iostream>
#include "list.h"


// TODO: crea nella lista una struttura per iterare gli elementi della lista
// List & begin(), & end()
// TODO: lista con doppio puntatore
// TODO: class iterator, operator++/==/!=/
// iterator &operator++()
int main() {
    List l;
    l.append(10);
    List::Node *ln = l.pop();
    l.show();
    return 0;
}
