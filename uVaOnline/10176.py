import sys

s = ''
for line in sys.stdin:
    s += line
    if '#' in line:
        s = s.replace('#', '')
        s = s.replace('\n', '')
        n = int(s, 2)
        if n % 131071 == 0:
            print ('YES')
        else:
            print ('NO')
        s = ''
