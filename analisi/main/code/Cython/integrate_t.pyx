def integrate_t(fun: callable, cnp.ndarray yn , float h):
    # calcola uno step di integrazione date le condizioni iniziali, lo step h e la funzione che regola il moto
    cdef cnp.ndarray k1 = h*fun(yn)
    cdef cnp.ndarray k2 = h*fun(yn + (1/2)*k1)
    cdef cnp.ndarray k3 = h*fun(yn + (1/2)*k2)
    cdef cnp.ndarray k4 = h*fun(yn + k3)
    # calcola la nuova posizione e la restituisce per l'iterazione successiva
    return yn + (1/6)*k1 + (1/3)*k2 + (1/3)*k3 + (1/6)*k4