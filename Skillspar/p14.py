import sys
cnt = 0
for line in sys.stdin:
    x = bin(int(line)).replace('0b','')
    while len(x) != 32:
      x = '0' + x
    y = ''
    for i in x:
        y = i + y
    y = int(y, 2)
    if cnt > 0:
      print(', ', end='')
    print(y, end='')
    cnt = 1
