#include <iostream>
#include <cstring>

#include "compito_3.h"

using namespace std;


int main(){
    vivaio V;
    InizializzaVivaio(V, 3);
    stampaVivaio(V);
    cout << "---------------------" << endl;
    piantaVivaio(V, "pino", 2);
    piantaVivaio(V, "abete", 1);
    piantaVivaio(V, "cipresso", 3);
    stampaVivaio(V);
    cout << "---------------------" << endl;
    piantaVivaio(V, "tiglio", 2);
    stampaVivaio(V);
    cout << "---------------------" << endl;
//    eliminaPiante(V,2,2);
    stampaVivaio(V);
    cout << "---------------------" << endl;
//    cout << quantePiante(V, "tiglio") << endl;
    cout << "---------------------" << endl;
//    Vivaio W = copiaVivaio(V);
//    stampaVivaio(W);
    return 0;
}
