//
// Created by gvent on 03/10/2023.
//

#include "Campominato.h"


Campominato::Cella::Cella(): icon{'X'},val{'0'},is_covered{true},is_marked(false) {}

Campominato::Cella::~Cella() {}

char Campominato::Cella::get_icon() const {
    return icon;
}

char Campominato::Cella::get_val() const {
    return val;
}


bool Campominato::Cella::get_is_covered() const {
    return is_covered;
}

void Campominato::Cella::make_mine() {
    val = 'B';
}

void Campominato::Cella::unveil() {
    is_covered = false;
}

void Campominato::Cella::counter() {
    val += 1;
}

void Campominato::Cella::flag() {
    is_marked = true;

}

void Campominato::Cella::togli_bandiera() {
    is_marked = false;

}

bool Campominato::Cella::get_flag() {
    return is_marked;
}


Campominato::Campominato(int n){
    if (n>0) {
        board = new Cella*[n*n];
        N = n;
        for (auto i = 0; i < n*n; ++i) {
            board[i] = new Cella;
        }
    } else {
        std::cout << "Valore di Default" << std::endl;
        board = new Cella*[9];
        N = 3;
        for (auto i = 0;  i < 9 ; ++i){
            board[i] = new Cella;
        }
    }
    is_gamestarted = false;
    is_gamestartable = false;
    is_gamelost = false;
    is_gamewon = false;
}

Campominato::~Campominato() {
    delete[] board;
}

std::ostream &operator<<(std::ostream &os, const Campominato &b) {
    if (!b.is_gamestartable) {
        os << "Inserire una mina per avviare il gioco\n";
    } else {
        for (int i = 0; i < b.N; i++) {
            for (int j = 0; j < b.N; j++) {
                if (b.board[b.N*i+j]->get_flag()) {
                    os << "F  ";
                } else if (b.board[b.N*i+j]->get_is_covered()) {
                    os << b.board[b.N*i+j]->get_icon() << "  ";
                } else {
                    if (b.board[b.N * i + j]->get_val() == '0') {
                        os <<"   ";
                    } else {
                        os << b.board[b.N * i + j]->get_val() << "  ";
                    }
                }
            }
            os << '\n';
        }
    }
    return os;
}

bool Campominato::aggiungi_mina(int r, int c) {
    if (getindex(r, c) != -1 && !is_gamestarted) {
        if (board[getindex(r,c)]->get_val() != 'B') {
            board[getindex(r, c)]->make_mine();
            aggiornacelle(r,c);
            is_gamestartable = true;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int Campominato::getindex(int r, int c) const {
    if ((0 <= r && r < N) && (0 <= c && c < N)) {
        return r*N+c;
    } else {
        return -1;
    }
}

void Campominato::scopri(int r, int c) {
    if (is_gamestartable && !is_gamelost && !is_gamewon) {
        int index = getindex(r, c);
        if (index != -1) {
            is_gamestarted = true;
            if (!board[index]->get_flag()) {
                board[index]->unveil();
                if (board[index]->get_val() == 'B') {
                    is_gamelost = true;
                }
                for (auto i = -1; i <= 1; ++i) {
                    for (auto j = -1; j <= 1; ++j) {
                        int newindex = getindex(r + i, c + j);
                        if (newindex != -1 && newindex != index && board[newindex]->get_val() == '0'
                            && !board[newindex]->get_flag() && !board[newindex]->get_is_covered()) {
                            scopri(r + i, c + j);
                        }
                    }
                }
            } else {
                std::cout << "casella marcata \n";
            }
        }
    }
}

void Campominato::aggiornacelle(int r, int c) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0)) {
                int index = getindex(r+i, c+j);
                if (index != -1 && board[index]->get_val() != 'B') {
                    board[index]->counter();
                }
            }
        }
    }
}

void Campominato::checkpartita() {
    for (int i = 0; i < N*N; i++) {
        if (board[i]->get_is_covered() && board[i]->get_val() != 'B'){
            return;
        }
    }
    is_gamewon = true;
}

int Campominato::get_N() const {
    return N;
}

void Campominato::aggiungi_bandiera(int r, int c) {
    if (getindex(r, c) != -1 && is_gamestarted) {
        board[getindex(r, c)]->flag();
    }
}

bool Campominato::togli_bandiera(int r, int c) {
    if (getindex(r, c) != -1 && is_gamestarted) {
        board[getindex(r, c)]->togli_bandiera();
        return true;
    }
    return false;
}
