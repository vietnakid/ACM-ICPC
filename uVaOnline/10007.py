from math import factorial

while True:
    n = int(input())
    if n == 0:
        break
    res = int(factorial(2*n) / int(factorial(n) * factorial(n)))
    res = int(res / (n+1))
    res = res * factorial(n);
    print(res)