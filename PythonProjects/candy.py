import matplotlib.pyplot as plt
import numpy as np

# Set the initial value of Q and the constant r
Q0 = 1
r = 0.5

# Define the time range
t = np.linspace(0, 10, 100)

# Compute the solution to the differential equation
Q = Q0 * np.exp(r * t)

# Plot the solution
plt.plot(t, Q)
plt.show()

print('finish')