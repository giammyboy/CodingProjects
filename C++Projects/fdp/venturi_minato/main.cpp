#include <iostream>
#include "Campominato.h"
#include <random>
#include <uchar.h>
#include <cstdlib>
#include <fcntl.h>

using namespace std;
int main() {
    int n, counter = 0;
    bool b;
    cout << "Inserire le dimensioni \n";
    cin >> n;
    Campominato* c = new Campominato(n);
    n = c->get_N();
    while (counter < n) {
        int randomrow = rand()%n;
        int randomcol = rand()%n;
        b = c->aggiungi_mina(randomrow, randomcol);
        if (b) {
            counter++;
        }
    }
    cout << *c;
    while (!c->is_gamelost && !c->is_gamewon) {
        int riga, colonna;
        int azione;
        cout << "Cosa vuoi fare? \n opzione 1: Scopri \n opzione 2: metti bandierina \n opzione 3: togli bandiera \n";
        cin >> azione;
        cout << "Inserire coordinate casella su cui lavorare \n";
        cin >> riga >> colonna;
        switch(azione) {
            case 1:   c->scopri(riga,colonna);
                break;
            case 2:   c->aggiungi_bandiera(riga, colonna);
                break;
            case 3:   c->togli_bandiera(riga,colonna);
                break;
            default:    cout << "Caso non presente \n";
        }

        cout << *c;
        c->checkpartita();
    }
    if (c->is_gamelost) {
        cout << "TI ASPETTA LA FOSSA DELLE PIPPE!! \n";
        return 0;
    }
    if (c->is_gamewon) {
        cout << "hai vinto violetta dell'Everest!!!!! \n";
        return 0;
    }
    return -1;
}