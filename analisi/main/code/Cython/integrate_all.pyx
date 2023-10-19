def integrate_all(fun: callable, y0: cnp.ndarray, double h) -> cnp.ndarray:
    # calcola per ogni istante di tempo l'integrazine in base alle condizioni di partenza

    # iniziallizza il vettore dei risultati a 0
    cdef cnp.ndarray res = np.zeros(shape=(self.n + 1, 2 * self.N + 2), dtype=DTYPE)
    # il primo istante è quello delle condizioni iniziali
    res[0] = y0

    # assegna al tempo da valutare il tempo iniziale
    t_eval = self.t

    # intera lungo il tempo
    for t, index in zip(t_eval, range(1, len(t_eval))):
        # per ogni istante di tempo aggiunge al risultato l'initegrazione corrispondente che riporta quindi posizione e velocità
        res[index] = integrate_t(fun, res[index - 1], h)
        # print(res[index], end="\n")

    return res