import pendoli
import numpy
from numpy import pi
import matplotlib.pyplot as plt
import time


# istanziamento dei pendoli, i parametri passati sono posizione iniziale e velocità angolare iniziale (di default = 0)
p1 = pendoli.Pendolo(thetaIniz=pi / 18)
p2 = pendoli.Pendolo(thetaIniz=-pi / 3)
p5 = pendoli.Pendolo(thetaIniz=pi / 5)

# istanziamento supporto, i parametri sono: pendoli da mettere sopra, M, m, l
Sys = pendoli.Sistema(pend=[p1], Mass=5, mass=2, lenght=3)
# funzione per simulare l'evoluzione, i parametri sono: durata, timestep, presenza del termine di damping-driving,
# coefficiente miu, angolo di equilibrio
ti = time.time()
Sys.simula(10, 0.01, damping=False, mi=0.6)
tf = time.time()
print("delta time = ", tf - ti)
plt.plot(Sys.t, Sys.E)
plt.show()
#Sys.animazione()


