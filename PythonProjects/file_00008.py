from re import S
from turtle import st
import school 

last_line = 0
while True:
    f = open("console.txt")
    string = f.readlines()
    if input() == '':
        exec(string[last_line])
        last_line += 1
    f.close()
    