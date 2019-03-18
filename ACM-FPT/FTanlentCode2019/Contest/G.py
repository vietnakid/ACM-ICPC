cen = raw_input().strip()
s = raw_input().strip()

s = s.replace('\n', '')
cen = cen.replace('\n', '').split(' ')

for c in cen:
    d = c[0] + '*' * (len(c)-1)
    s = s.replace(c, d)

print s