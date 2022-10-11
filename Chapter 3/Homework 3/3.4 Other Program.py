from collections import defaultdict, deque
from copy import copy, deepcopy
import time

def magicSum(n):
    return int((n*n * (n*n + 1)) / 6)

def validate(sumDict, n):
    for k, v in sumDict.items():
        if v > magicSum(n):
            return False
    return True

def check(sumDict, n):
    for k, v in sumDict.items():
        if v != magicSum(n):
            return False
    return True

def isValid(m, n):
    rowSum = defaultdict(int)
    colSum = defaultdict(int)
    diagSum = defaultdict(int)

    isLeft = False

    for i in range(n):
        for j in range(n):
            if m[i][j] == 0:
                isLeft = True
            rowSum[i] += m[i][j]
            colSum[j] += m[i][j]
            if i == j:
                diagSum[0] += m[i][j]
            if i + j == n - 1:
                diagSum[n - 1] += m[i][j]

    if isLeft:
        return (validate(rowSum, n) and validate(colSum, n) and validate(diagSum, n))
    return (check(rowSum, n) and check(colSum, n) and check(diagSum, n))

def next(cur, m, n):
    possible = []
    for i in range(n):
        for j in range(n):
            if m[i][j] == 0:
                nextM = deepcopy(m)
                nextM[i][j] = cur
                if isValid(nextM, n):
                    possible.append(nextM)
    return possible

def gen(n):
    startM = [[0 for x in range(n)] for y in range(n)]
    magic = []
    Q = deque([(1, startM)])
    while len(Q):
        state = Q.popleft()
        cur = state[0]
        m = state[1]
        if cur == n * n + 1:
            magic.append(m)
            continue
        for w in next(cur, m, n):
            Q.append((cur + 1, w))
    return magic

start_time = time.time()
magic = gen(3)
elapsed_time = time.time() - start_time
print("Elapsed time: ", elapsed_time)
