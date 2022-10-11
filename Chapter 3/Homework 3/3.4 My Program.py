from itertools import permutations
from array import *
import numpy
import time


length = 3

start_time = time.time()

array = list(range(1, length ** 2 + 1))
twodarray = []
perms = list(permutations(array))

squaresum = length * ( length ** 2 + 1) / 2

totalgood = []
count = 0
for permutation in perms:
    x = numpy.array_split(permutation, length)
    twodarray.insert(0, x)

for permutation in twodarray:
    status = True
    for arr in permutation:
        if sum(arr) != squaresum:
            status = False


    tempperm = numpy.transpose(permutation)
    for arr in tempperm:
        if sum(arr) != squaresum:
            status = False

    tempsum = 0
    for i in range(0, len(permutation)):
        tempsum = tempsum + permutation[i][i]

    if tempsum != squaresum:
        status = False

    if status:
        count = count + 1

elapsed_time = time.time() - start_time

print("Time Elapsed: ", elapsed_time)
