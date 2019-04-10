n = 3.0
C = 2.0


c = C/n
e = 1. - c
s = 0
for leng in range(2, 100):
    s += leng*pow(c, leng-2)*e/n
print s


s = 0
r = (n-C)/(n*n)
for leng in range(2, 1000):
    s += leng*pow(c, leng-2)

print r*s
print s, r
