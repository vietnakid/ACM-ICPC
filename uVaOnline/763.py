import sys

fibo = [1]*1001
fibo[1] = 2

for i in range(2, 1001):
    fibo[i] = fibo[i-1] + fibo[i-2]

inp = []
while True:
    try:
        a = input()[::-1]
        if (len(a) == 0):
            break
        b = input()[::-1]
        c = input()
        # print(a, b)

        s1 = 0
        s2 = 0
        for i, x in enumerate(a):
            s1 += (ord(x) - ord('0')) * fibo[i]
        for i, x in enumerate(b):
            s2 += (ord(x) - ord('0')) * fibo[i]
        s = s1 + s2
        i = 1000
        res = '0'

        while i >= 0:
            # print(s, i, fibo[i])
            if s >= fibo[i]:
                s -= fibo[i]
                if i != 0:
                    i -= 1
                    res += '10'
                else:
                    res += '1'
            else:
                res += '0'
            i -= 1
        i = 0
        while res[i] == '0' and i < len(res)-1:
            i += 1
        res = res[i:]
        print(res + '\n')
    except:
        break


