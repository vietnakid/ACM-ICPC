n = 200
k = 5
m = 3

def fibo(n):
    if n == 0: 
        return '0'
    if n == 1: 
        return '1'
    f = ['0', '1']
    for i in range(2, n+1):
        s = f[i-2] + f[i-1]
        f.append(s)
    return s

f = fibo(8)
a1 = 0
a0 = 0
for x in f:
    if x == '1':
        a1 += 1
    else:
        a0 += 1
# print f
print len(f), a0, a1

def cal(n, s):
    


res = ''
count = 0
for i in range(m):
    cnt = cal(n, res + '1')
    