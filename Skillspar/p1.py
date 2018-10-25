n = int(raw_input())
for i in xrange(n):
    x = raw_input()
    # print bin(int(x, 16)).replace('0b', '')
    print "{0:b}".format(int(x, 16))