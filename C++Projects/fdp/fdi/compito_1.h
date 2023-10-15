//
// Created by Gianmarco Rossi on 09/10/23.
//

#ifndef FDI_COMPITO_1_H
#define FDI_COMPITO_1_H

#define MAX 51

#include <iostream>
#include <cstring>


 // STRUTTURE
struct opera {
    char autore[MAX] = {0};
    char titolo[MAX] = {0};
    bool occupata;
};

struct museo {
    int n_sale;
    int max_quadri;
    opera** mat;
};

// INIZIALIZZAZIONE
void InizializzaMuseo(museo& m, int n, int q) {
    m.n_sale = abs(n);
    m.max_quadri = abs(q);
    m.mat = new opera*[m.n_sale];
    for (int i = 0; i < m.n_sale; ++i) {
        m.mat[i] = new opera[m.max_quadri];
        for (int j = 0; j < m.max_quadri; ++j) {
            m.mat[i][j].occupata = false;
        }
    }
}

//FUNZIONI ACCESSORIE

int contaOccupati(opera* s, int l) {
    int conta = 0;
    for (int i = 0; i < l; ++i) {
        if (s[i].occupata) ++conta;
    }
    return conta;
}

int indiceSala(museo& m) {
    int min = contaOccupati(m.mat[0], m.max_quadri);
    int res = 0;
    for (int i = 0; i < m.n_sale; ++i) {
        if (contaOccupati(m.mat[i], m.max_quadri) < min) {
            min = contaOccupati(m.mat[i], m.max_quadri);
            res = i;
        }
    }
    return res;
}





// FUNZIONI OBBLIGATORIE
bool aggiungiOpera(museo& m, char* autore, char* titolo) {
    // stringa valida
    if (strlen(autore) <= 0 || strlen(autore) > 50 || strlen(titolo) <= 0 || strlen(titolo) > 50) return false;
    // non è una copia
    for (int i = 0; i < m.n_sale; ++i) {
        for (int j = 0; j < m.max_quadri; ++j) {
            if (strcmp(m.mat[i][j].autore, autore) == 0 &&  strcmp(m.mat[i][j].titolo, titolo) == 0) return false;
        }
    }


    opera* s = m.mat[indiceSala(m)];

    if (contaOccupati(s, m.max_quadri) != m.max_quadri) {
        for (int i = 0; i < m.max_quadri; ++i) {
            if (!s[i].occupata) {
                strcpy(s[i].autore, autore);
                strcpy(s[i].titolo, titolo);
                s[i].occupata = true;
                return true;
            }
        }
    }
    return false;
}


bool eliminaOpera(museo& m, char* autore, char* titolo) {
    // stringa valida
    if (strlen(autore) <= 0 || strlen(autore) > 50 || strlen(titolo) <= 0 || strlen(titolo) > 50) return false;

    for (int i = 0; i < m.n_sale; ++i) {
        for (int j = 0; j < m.max_quadri; ++j) {
            if(strcmp(m.mat[i][j].autore, autore) == 0 && strcmp(m.mat[i][j].titolo, titolo) == 0) {
                m.mat[i][j].occupata = false;
                return true;
            }
        }
    }
    return false;
}

void stampaMuseo(museo& m) {
    for (int i = 0; i < m.n_sale; ++i) {
        std::cout << "<" << i + 1 << "> ";
        if (contaOccupati(m.mat[i], m.max_quadri) == 0) {
            std::cout << "-";
        } else {
            for (int j = 0; j < m.max_quadri; ++j) {
                if (m.mat[i][j].occupata) {
                    std::cout << "("<< m.mat[i][j].autore << ", " << m.mat[i][j].titolo << ") ";
                }
            }
        }
        std::cout << std::endl;
    }
}

int opereAutore(museo& m, char* autore, int s) {
    // autore valido
    if (strlen(autore) <= 0 || strlen(autore) > 50) return false;

    int res = 0;

    if (s >= 1 && s <= m.n_sale) {
        for (int j = 0; j < m.max_quadri; ++j) {
            if (strcmp(m.mat[s - 1][j].autore, autore) == 0) ++res;
        }
    }
    return res;
}



#endif //FDI_COMPITO_1_H
