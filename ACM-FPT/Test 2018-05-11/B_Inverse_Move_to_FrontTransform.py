TC = int(input())

for tc in range(TC):
    n = int(input())
    arr = [int(x) for x in input().split()]
    crr = [chr(x) for x in range(ord('a'), ord('z') + 1)]
    res = ""
    for x in arr:
        c = crr[x]
        res += c
        crr.remove(c)
        crr.insert(0, c)
    print(res)
