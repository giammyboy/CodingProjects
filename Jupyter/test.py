import numpy as np

def norm(*args):
  res = 0  
  for elem in args:
    res += elem ** 2
  return np.sqrt(res)

rmin = .5
