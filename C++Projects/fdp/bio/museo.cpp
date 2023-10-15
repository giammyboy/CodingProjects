//
// Created by Gianmarco Rossi on 09/10/23.
//

#define MAX 51


struct opera {
    char autore[MAX] = {0};
    char titolo[MAX] = {0};
};

struct museo {
    int n_sale;
    int max_quadri;
    opera** mat;
};

void IniazializzaMuseo(museo& m, int n, int q) {
    m.n_sale = n;
    m.max_quadri = q;
    m.mat = new opera*[m.n_sale];
    for (int i = 0; i < m.n_sale; ++i) {
        m.mat[i] = new opera[m.max_quadri];
    }
}