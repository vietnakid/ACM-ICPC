x = 0
res = 1000
for yy in range(-1, 2, 2):
    y = x + yy*3
    for zz in range(-1, 2, 2):
        z = y + zz*7
        for ww in range(-1, 2, 2):
            w = z + ww*12
            print x, y, z, w
            print abs(x - w)
            res = min(res, abs(x - w))

print res