n = int(input())

for i in range(n):
    a, b = input().split()
    a = int(a[::-1])
    b = int(b[::-1])
    c = int(str(a + b)[::-1])
    print(c)



