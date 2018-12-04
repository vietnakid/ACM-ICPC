6152067383005334336844, 26)
l = int2base(26, 26)
print l
for x in l:
    if x >= '0' and x <= '9':
        print chr(ord(x) - ord('0') + ord('A')),
    else:
        print chr(ord(x) - o