x = [0, 4]
while x[len(x)-1] % 83 != 0:
    n = len(x)
    value = 4*x[n-1] - 3 *x[n-2]
    x.append(value)
    print value, len(x)
