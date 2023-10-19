def dSdt(cnp.ndarray S):
    # S   di tipo [ang1, ome1, ..., angk, omek, pos, vel]
    # res di tipo [ome1, acc1, ..., omek, acck, vel, acc]
    # inizializzo il vettore dei risultati a 0
    cdef cnp.ndarray res = np.zeros(2 * self.N + 2, dtype=DTYPE)

    # calcolo l'accelerazione del supporto 
    cdef double acc = self.m *  sum(self.l * (S[k + 1] ** 2 * sin(S[k])) - g * sin(2 * S[k]) 
                                    for k in range(0, 2 * self.N, 2))
    acc /= self.M + self.m * sum(sin(S[k]) ** 2 
                                for k in range(0, 2 * self.N, 2))

    # calcolo omega e acc ang
    cdef double acc_ang
    for k in range(0, 2 * self.N, 2):
        # sposto le velocità dal vettore iniziale a quello dei risultati 
        res[k] = S[k + 1]
        # calcolo l'acc ang in funzione della velocità e posizione
        acc_ang = (g * sin(S[k]) - acc * cos(S[k])) / self.l
        # controllo se è attivo il damping e effettuo le modifiche necessarie all'accelerazione
        if damping: acc_ang -= mi * S[k + 1] * ((S[k] / teta0) ** 2 - 1)
        # aggiungo l'acc ang ai risultati
        res[k + 1] = acc_ang
    
    # sposto la velocità del supporto dal vettore iniziale a quello dei risultati
    res[2 * self.N] = S[2 * self.N + 1]
    # aggiungo l'accelerazione al vettore dei risultati
    res[2 * self.N + 1] = acc
    return res    