import sys

fibo = [1]*1001
fibo[1] = 2

for i in range(2, 1001):
    fibo[i] = fibo[i-1] + fibo[i-2]

for line in sys.stdin:
    line = int(line)
    print(fibo[line])
