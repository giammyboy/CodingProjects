import scratch 
import time 


def calculate_time(func):

    def inner(*args, **kwargs):
        start = time.time()

        func(*args, **kwargs)
        
        end = time.time()

        print('Time used: ', end - start, 'sec')

    return inner

@calculate_time
def fun():
    input = open('test.txt', 'w')
    for n in range(50000):
        input.write(str(scratch.fibonacci(n)) + '\n')
    return 0


if __name__ == '__main__':
    fun()
