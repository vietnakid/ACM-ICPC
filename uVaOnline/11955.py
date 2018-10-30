C = [[0 for x in range(51)] for x in range(51) ]

for i in range(1, 51):
    C[i][1] = i
    for j in range(2, i+1):
        C[i][j] = C[i-1][j] + C[i-1][j-1]


TC = int(input())

for tc in range(TC):
    line = input()
    print("Case %d: " % (tc+1), end='')
    posPlus = line.find('+')
    first = line[1:posPlus]
    posPow = line.find('^')
    second = line[posPlus+1:posPow-1]
    num = int(line[posPow+1:])
    # print(first, second, num)
    a = num
    b = 0
    for i in range(num+1):
        if (C[num][b] > 1):
            print(str(C[num][b]) + '*', end='')
        if (a > 0):
            print(first, end='')
            if (a > 1):
                print('^' + str(a), end='')
        if (a > 0 and b > 0):
            print('*', end = '')
        if (b > 0):
            print(second, end='')
            if (b > 1):
                print('^' + str(b), end='')
        if (i != num):
            print('+', end='')
        a -= 1
        b += 1
    print()