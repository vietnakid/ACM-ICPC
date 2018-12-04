import string
digs = string.digits + string.ascii_letters


def int2base(x, base):
    if x < 0:
        sign = -1
    elif x == 0:
        return digs[0]
    else:
        sign = 1

    x *= sign
    digits = []

    while x:
        digits.append(digs[int(x % base)])
        x = int(x / base)

    if sign < 0:
        digits.append('-')

    digits.reverse()

    return ''.join(digits)




base26 = [26]

for i in range(30):
    x = base26[i]
    x = x * 26
    base26.append(x)

print base26


key = 404982000012063942418231892259

sum = 0
index = 0
while sum < key:
    sum += base26[index]
    print index, sum
    index += 1

print 'len = ', index

index -= 1
sum -= base26[index]
print 'sum = ', sum
key -= sum + 1

index -= 1
c = key / base26[index]
remain = key - (c * base26[index])

print chr(c + ord('A')), key, base26[index], remain


flag = 'T'


l = int2base(remain, 26)
print 'l = ', l
for x in l:
    if x >= '0' and x <= '9':
        flag += chr(ord(x) - ord('0') + ord('A'))
    else:
        flag += chr(ord(x) - ord('a') + ord('K'))

print flag
#THISISTOOEASYEASYEASY