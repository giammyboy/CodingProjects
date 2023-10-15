from getopt import gnu_getopt
from glob import glob


import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

global g 
g = 9.8

def s_y(t: float, v0_y: float, s0_y: float = 0):
    return -0.5 * g * (t ** 2) + v0_y * t + s0_y

def s_x(t: float, v0_x: float):
    return v0_x * t



t = np.linspace(0, 5, 100)
v = np.linspace(0, 10, 100)
fig, ax = plt.subplots(figsize=(10, 5))
plt.plot(s_x(t, v), s_y(t, 5, 100))
plt.show()
