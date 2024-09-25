from time import *
from random import *
def init(size):
    return [i for i in range(size)]
def init_random(size):
    return [random() for i in range(size)]
def linear_search(x, TARGET):
    for element in x:
        if element == TARGET:
           return True
    return False
def binary_search(x, TARGET):
    start = 0
    end = len(x) - 1
    while start <= end:
        mid = (start + end) // 2
        if x[mid] == TARGET:
            return True
        elif x[mid] > TARGET:
            end = mid - 1
        else:
            start = mid + 1
    return False
size = 100000
search_size = 10000
x = init(size)
start = time()
for _ in range(search_size):
        binary_search(x, random())
stop= time()
print('Time in binary search: ', stop - start)
x = init_random(size)
start = time()
for _ in range(search_size):
    linear_search(x, random())
stop= time()
print('Time in linear search: ', stop - start)
