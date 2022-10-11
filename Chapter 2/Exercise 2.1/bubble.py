import numpy as np
import time

arr = np.random.randint(1, 2000, 10000)


def sort(array):
    for i in range(0, len(array) - 1):
        for j in range(0, len(array) - 1 - i):
            if arr[j + 1] < arr[j]:
                temp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = temp
    return array

print("Started Sorting")
start = time.time()
sort(arr)
end = time.time();

print("Time took:", end-start)
