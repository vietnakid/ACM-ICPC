while True:
    a = input()
    a = int(a)
    if a == 0:
        break
    if a % 17 == 0:
        print(1)
    else:
        print(0)
