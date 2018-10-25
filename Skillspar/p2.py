n = int(raw_input())
s = raw_input()
arr = []
for i in range(n):
    x = raw_input()
    cnt = 0
    for a in x.split(' '):
        if a == s:
            cnt += 1
    arr.append((cnt, x))

arr.sort()

for x in arr:
    print x[1]