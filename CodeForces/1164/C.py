import itertools

cnt = 0
for x in itertools.permutations(range(7)):
    check = True
    for i in range(6):
        if (x[i] == 1 and x[i+1] == 0) or (x[i] == 0 and x[i+1] == 1):
            check = False
    if check:
        cnt += 1

print cnt