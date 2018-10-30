import sys
for line in sys.stdin:
    n, a = line.split()
    a = int(a)
    n = int(n)
    s = 0
    A = a
    for i in range(1, n+1):
        s += i * A
        A *= a
    print(s)
