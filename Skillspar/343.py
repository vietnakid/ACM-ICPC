import sys
for line in sys.stdin:
    a, b = line.split()
    check = False
    ma = max(a)
    if ma >= 'A':
        ma = ord(ma) - ord('A') + 10
    else:
        ma = ord(ma) - ord('0')
    mb = max(b)
    if mb >= 'A':
        mb = ord(mb) - ord('A') + 10
    else:
        mb = ord(mb) - ord('0')
    ma = max(ma, 1)
    mb = max(mb, 1)
    for i in range(ma+1,37):
        if not check:
            for j in range(mb+1, 37):
                if int(a, i) == int(b, j):
                    check = True
                    print("%s (base %d) = %s (base %d)" % (a, i, b, j))
                    break
    if not check:
        print("%s is not equal to %s in any base 2..36" % (a, b))