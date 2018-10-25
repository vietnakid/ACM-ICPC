import sys
import math

for line in sys.stdin:
    n = line[:6]
    p = line[7:]
    a, b = n.split('.')
    if a == '0':
        b = int(b)
        p = int(p)
        pa = pow(b, p)
        padding = 80 - len(str(pa))
        pa = '.' + '0'*padding + str(pa)
        print (pa)
    else:
        a = a+b
        a = int(a)
        p = int(p)
        pa = pow(a, p)
        n = float(n)
        pn = pow(n, p)
        leng = math.ceil(math.log10(pn))
        a = str(pa)[:leng] + '.' + str(pa)[leng:].rstrip('0')
        print (a)