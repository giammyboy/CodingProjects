import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(projection='3d')

# Make data
u = np.linspace(10, -10, 10)
v = np.linspace(10, -10, 10)
w = np.linspace(10, -10, 10)
k = 1.0
x = k * v * np.sqrt(u**2 + v**2 + w**2)
y = -k * u * np.sqrt(u**2 + v**2 + w**2)
z = k * w * np.sqrt(u**2 + v**2 + w**2)

print(x, y, z)

X = np.outer(x, u)
Y = np.outer(y, v)
Z = np.outer(z, w)

# Plot the surface
ax.quiver(Y, Y, Z, X, Y, Z)

# Set an equal aspect ratio
ax.set_aspect('equal')

plt.show()
