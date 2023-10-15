import matplotlib as mpl
import numpy as np
from matplotlib import pyplot as plt


x = np.linspace(0, 10, 100)
fig, ax = plt.subplots()
ax.plot(x, x**3, label="cubic")
ax.plot(x, x**2 + 10, label="quadratic")

ax.legend(loc="upper left")
plt.show()