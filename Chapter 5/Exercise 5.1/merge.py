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

    print(b)
    print(c)

def merge(b, c, a):
    i = 0
    j = 0
    k = 0
    while i < len(b) and j < len(c):
        if b[i] <= c[j]:
            a[k] = b[i];
            i = i + 1
        else:
            a[k] = c[j];
            j = j + 1
        k = k + 1
    if j == len(b):
        while j < len(c):
            a[k] = c[j]
            j += 1
            k += 1
    else:
        while i < len(b):
            a[k] = b[i]
            i += 1
            k += 1

a = ["E", "X", "A", "M", "P", "L", "E"]

mergesort(a)

print(a)
