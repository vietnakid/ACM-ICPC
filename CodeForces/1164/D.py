
i = 1
while True:
    i += 1
    a = i * 29
    if str(a)[-2:] == "29":
        b = a
        s = 0
        while (b > 0):
            s += b % 10
            b /= 10
        print a, s
        if s == 29:
            print a
            break