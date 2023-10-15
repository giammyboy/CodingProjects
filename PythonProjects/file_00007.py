import app_1 as app


global data, mn

data = {0: app.Number('1'), 1: app.Number('1')}
data1 = {0:1, 1:1}

def fibonacci(n):
    if n not in data1.keys():
        data1[n] = fibonacci(n - 1) + fibonacci(n - 2)
    return data1[n]

def fibonacci_n(n):
    if n not in data.keys():
        data[n] = fibonacci_n(n - 1) + fibonacci_n(n - 2)
    return data[n]
    