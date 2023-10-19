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
  #plt.savefig(f"analisi/energy{index}.png", dpi=600)
  plt.show()



# istanziamento dei pendoli, i parametri passati sono posizione iniziale e velocità angolare iniziale (di default = 0)
p1 = pendolo.Pendolo(thetaIniz=pi / 36)
p2 = pendolo.Pendolo(thetaIniz=pi / 5)
p5 = pendolo.Pendolo(thetaIniz=pi / 3)
p6 = pendolo.Pendolo(thetaIniz=-pi / 7)

# istanziamento supporto, i parametri sono: pendoli da mettere sopra, M, m, l
a = pendolo.Sistema(pend=[p1], Mass=10, mass=2, lenght=.3)
b = pendolo.Sistema(pend=[p1], Mass=10, mass=2, lenght=.3)
# funzione per simulare l'evoluzione, i parametri sono: durata, timestep, presenza del termine di damping-driving,
# coefficiente miu, angolo di equilibrio
# ti = time.time()
# Sys.simula(10, 0.0001, damping=0, mi=1.9, method=1)
# tf = time.time()
# print("delta time = ", tf - ti)

# plot_energy(Sys, 3)
# graph(Sys)

a.simula(200, .1, damping=0, mi=.4, method=1)
b.simula(200, .1, damping=0, mi=1.9, method=2)
fig, axs = plt.subplots(nrows=1, ncols=2)
fig.set_figheight(5)
fig.set_figwidth(15)
# axs[0].set_ylim(0, max(np.max(a.E), np.max(b.E)) + 1)
# axs[1].set_ylim(0, max(np.max(a.E), np.max(b.E)) + 1)
axs[0].set_ylim(min(np.min(a.E), np.min(b.E)), max(np.max(a.E), np.max(b.E)))
axs[1].set_ylim(min(np.min(a.E), np.min(b.E)), max(np.max(a.E), np.max(b.E)))
axs[0].plot(a.t, a.E)
axs[1].plot(b.t, b.E)
# plt.savefig("compare_method_n1pendoli.png", dpi=700)
plt.show()
# plot_energy(a, 3)
# graph(a)
# a.animazione()
# Sys.diff()

# fig, axs = plt.subplots(nrows=1, ncols=2)
# fig.set_figheight(5)
# fig.set_figwidth(15)
# # axs[0].set_ylim(0, max(np.max(a.E), np.max(b.E)) + 1)
# # axs[1].set_ylim(0, max(np.max(a.E), np.max(b.E)) + 1)
# axs[0].set_xlabel("Time [s]")
# axs[0].set_ylabel("Theta [rad]")
# axs[1].set_xlabel("Theta [rad]")
# axs[1].set_ylabel("Omega [rad s^-1]")
# for p in a.pendoli:
#   axs[0].plot(a.t, p.theta)
#   axs[1].plot(p.theta, p.omega)
# #plt.savefig("spazio_fasi_tempo_angolo_n1pendoli_damping.png", dpi=700)
# plt.show()
