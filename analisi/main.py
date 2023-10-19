import pendolo
import numpy as np
from numpy import pi
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import time

def graph(s: pendolo.Sistema):
  fig, axs = plt.subplots(nrows=2, ncols=2)
  fig.set_figwidth(7)
  fig.set_figheight(7)

  for p in s.pendoli:
      axs[0, 0].plot(s.t, p.theta)
      axs[0, 0].set_xlabel("Time [s]")
      axs[0, 0].set_ylabel("Theta [rad]")
      axs[0, 1].plot(p.theta, p.omega)
      axs[0, 1].set_xlabel("Theta [rad]")
      axs[0, 1].set_ylabel("Omega [rad s^-1]")
  axs[1, 0].plot(s.t, s.x)
  axs[1, 0].set_xlabel("Time [s]")
  axs[1, 0].set_ylabel("Position [m]")
  axs[1, 1].plot(s.x, s.v)
  axs[1, 1].set_xlabel("Position [m]")
  axs[1, 1].set_ylabel("Velocity [m s^-1]")
  # plt.savefig('fig1.png', dpi=600)
  plt.show()

def plot_energy(s: pendolo.Sistema, index = 1):
  fig, axs = plt.subplots(1)
  fig.set_figwidth(7)
  fig.set_figheight(7)
  axs.set_xlim(0, np.max(s.t))
  axs.set_ylim(0, np.max(s.E) + 1)
  axs.plot(s.t, s.E)
  plt.savefig("energy.png", dpi=600)
  plt.show()






# istanziamento dei pendoli, i parametri passati sono posizione iniziale e velocità angolare iniziale (di default = 0)
p1 = pendolo.Pendolo(thetaIniz=pi / 18)
p2 = pendolo.Pendolo(thetaIniz=-pi / 8)
p5 = pendolo.Pendolo(thetaIniz=pi / 16)
p6 = pendolo.Pendolo(thetaIniz=-pi / 7)

# istanziamento supporto, i parametri sono: pendoli da mettere sopra, M, m, l
Sys = pendolo.Sistema(pend=[p1, ], Mass=5, mass=2, lenght=.5)
# funzione per simulare l'evoluzione, i parametri sono: durata, timestep, presenza del termine di damping-driving,
# coefficiente miu, angolo di equilibrio
ti = time.time()
Sys.simula(10, 0.001, damping=0, mi=1.9)
tf = time.time()
print("delta time = ", tf - ti)
#Sys.animazione()
plot_energy(Sys, 1)
# Sys.simula(10, 0.01, damping=0, mi=1.9)
# plot_energy(Sys, 2)
# Sys.simula(10, 0.001, damping=1, mi=1.9)
# plot_energy(Sys, 3)
# Sys.simula(10, 0.01, damping=1, mi=1.9)
#Sys.diff()
#graph(Sys)

