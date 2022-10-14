def mergesort(a):
    b = []
    c = []

    if len(a) > 1:
        for i in range(int(len(a) / 2)):
            b.append(a[i])
        for i in range(int(len(a) / 2), len(a)):
            c.append(a[i])
        mergesort(b)
        mergesort(c)
        merge(b,c,a)
        print()

def merge(arrb, arrc, arr):
    p = len(arrb)
    q = len(arrc)
    i = 0
    j = 0
    k = 0
    print(arrb)
    print(arrc)
    while i < p and j < q:
        if arrb[i] <= arrc[j]:
            arr[k] = arrb[i]
            i += 1
        else:
            arr[k] = arrc[j]
            j += 1
        k += 1
    if i == p:
        d = 0
        for i in range(j, q):
            arr[k + d] = arrc[i]
            d += 1
    else:
        d = 0
        for i in range(i, p):
            arr[k + d] = arrb[i]
            d += 1



a = ["E", "X", "A", "M", "P", "L", "E"]

mergesort(a)

print(a)
