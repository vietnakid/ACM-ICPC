src = int(raw_input())
dst = int(raw_input())

s = raw_input().strip()
s = s.replace(',', '').split(' ')

arr = []
arr.append(s)
n = len(s)
for i in range(n - 1):
    s = raw_input().strip()
    s = s.replace(',', '').split(' ')
    arr.append(s)

d = [1000000000]*n
isFree = [True]*n
d[src] = 0
trace = [-1]*n

while True:
    u = -1
    mmin = 1000000000
    for i in range(n):
        if isFree[i] and mmin > d[i]:
            mmin = d[i]
            u = i
    if u == -1:
        break
    isFree[u] = False
    for i in range(n):
        if isFree[i] and int(arr[u][i]) != 0 and d[i] > d[u] + int(arr[u][i]):
            d[i] = d[u] + int(arr[u][i])
            trace[i] = u
res = []
while trace[dst] != -1:
    res.append(str(dst))
    dst = trace[dst]

res.append(str(src))

print ' '.join(res[::-1])
