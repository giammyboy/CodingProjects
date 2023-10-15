//
// Created by Gianmarco Rossi on 10/10/23.
//

#ifndef FDI_COMPITO_3_H
#define FDI_COMPITO_3_H

#include <iostream>
#include <cstring>

struct pianta {
    char nome[21] = {0};
    pianta* next = nullptr;
};

struct vivaio {
    int n = 0;
    pianta** file_piante;
};

void InizializzaVivaio(vivaio& v, int n) {
    v.n = n;
    v.file_piante = new pianta*[v.n];
    for (int i = 0; i < v.n; ++i) {
        v.file_piante[i] = nullptr;
    }
}

int contaPiante(pianta* fila) {
    int conta = 0;
    for (pianta* i = fila; i != nullptr; i = i->next) {
        ++conta;
    }
    return conta;
}

int filaMinore(vivaio& v) {
    int min = contaPiante(v.file_piante[0]);
    int res = 0;
    for (int i = 0; i < v.n; ++i) {
        if (contaPiante(v.file_piante[i]) < min) {
            res = i;
            min = contaPiante(v.file_piante[i]);
        }
    }
    return res;
}

pianta* testaFila(pianta* fila) {
    pianta* res;
    for (pianta* i = fila; i != nullptr; i = i->next) {
        res = i;
    }
    return res;
}


bool piantaVivaio(vivaio& v, char* nome, int n) {
    if (strlen(nome) <= 0 || strlen(nome) > 20 || n < 0) return false;

    pianta* testa = testaFila(v.file_piante[filaMinore(v)]);
    if (testa == nullptr) {
        testa = new pianta;
        strcpy(testa->nome, nome);
        n -= 1;
    } else {
        for (int i = 0; i < n; ++i) {
            testa->next = new pianta;
            testa = testa->next;
            strcpy(testa->nome, nome);
        }
    }
    return true;
}

void stampaVivaio(vivaio& v) {
    std::cout << v.n << std::endl;
    for (int i = 0; i < v.n; ++i) {
        pianta* testa = v.file_piante[i];
        if (testa == nullptr) {
            std::cout << "-";
        } else {
            for (pianta* iter = testa; iter != nullptr; iter = iter->next) {
                std::cout << iter->nome;
            }
        }

        std::cout << std::endl;
    }
}




#endif //FDI_COMPITO_3_H
