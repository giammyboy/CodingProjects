import numpy as np

t = [[0, 0, 0, 0],
     [.5, 0, 0, 0],
     [0, .5, 0, 0],
     [0, 0, 0, 1]]
tb = [1/6, 1/3, 1/3, 1/6]

for i in range(4):
  for j in range(4):
    if tb[i]*t[i][j] + tb[j]*t[j][i] == tb[i]*tb[i]:
      print(i, j, True)
    else:
      print(i, j, False)