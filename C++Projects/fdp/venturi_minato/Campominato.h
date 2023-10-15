//
// Created by gvent on 03/10/2023.
//

#ifndef UNTITLED3_CAMPOMINATO_H
#define UNTITLED3_CAMPOMINATO_H
#include <iostream>

class Campominato {
public:
    class Cella {
    public:
        char icon;
        char val;
        bool is_covered;
        bool is_marked ;
        Cella();
        ~Cella();
        char get_icon() const;
        char get_val() const;
        bool get_is_covered() const;
        void unveil();
        void make_mine();
        void counter();
        void flag();
        void togli_bandiera();
        bool get_flag();
    };
    Cella **board;
    int N;
    bool is_gamestarted;
    bool is_gamestartable;
    bool is_gamelost;
    bool is_gamewon;
    int getindex(int r, int c) const;
    void aggiornacelle (int r, int c);
    int get_N() const;

public:
    Campominato(int n =3);
    ~Campominato();

    friend std::ostream &operator<<(std::ostream &os, const Campominato &b);

    bool aggiungi_mina(int r, int c);
    void aggiungi_bandiera(int r, int c);
    bool togli_bandiera(int r, int c);
    void scopri(int r, int c);
    void checkpartita() ;
    void check();
};


#endif //UNTITLED3_CAMPOMINATO_H
