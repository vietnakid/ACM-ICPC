fac = [1]*201

for i in range(2, 201):
    fac[i] = fac[i-1] * i

TC = int(input())

for tc in range(TC):
    a = input().split()
    n = int(a[0])
    k = int(a[1])
    s = 0
    for i in range(k):
        x = int(a[i+2])
        s += x
    nWhile = n-s+1
    if (k > nWhile):
        print(0)
    else:
        res = fac[nWhile] / (fac[nWhile-k] * fac[k])
        print(res)
