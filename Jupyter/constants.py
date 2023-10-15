import numpy as np

m = 0.1
M = 0.5
a = 30
mis = 0.75
mid = 0.50
g = 10
mt = m + M

num = mis * m * g * np.cos(a) - m * g * np.sin(a)
den = (-mis * m * np.sin(a) + m * np.cos(a))/mt
res = num / den
print(res)


num = mid * m * g * np.cos(a) - m * g * np.sin(a) + mid * m * 2
den = (-mis * m * np.sin(a) + m * np.cos(a))/mt
res = num / den
print(res)