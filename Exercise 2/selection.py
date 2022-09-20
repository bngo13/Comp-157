import numpy as np
import time

array = np.random.randint(1, 2000, 10000)

def sort(arr):
    for i in range(0, len(arr)):
        potential_small = i
        for j in range(i, len(arr)):
            if arr[i] > arr[j]:
                if arr[potential_small] > arr[j]:
                    potential_small = j
            temp = arr[i]
            arr[i] = arr[potential_small]
            arr[potential_small] = temp

    return arr

print("Started Sorting")
start = time.time()
sort(array)
end = time.time();

print("Time took:", end-start)
