TC = int(input())

def tobase4(s):
    res = ''
    for x in s:
        if x == 'V':
            res += '0'
        elif x == 'U':
            res += '1'
        elif x == 'C':
            res += '2'
        elif x == 'D':
            res += '3'
    return res

def cal(n1, n2, o):
    if o == 'A':
        return n1 + n2

print ('COWCULATIONS OUTPUT')
for tc in range(TC):
    s1 = input()
    n1 = tobase4(s1)
    s2 = input()
    n2 = tobase4(s2)
    o1 = input()
    n2 = cal(n1, n2, o1)
    o2 = input()
    n2 = cal(n1, n2, o1)
    o3 = input()
    n2 = cal(n1, n2, o1)
    s3 = input()
    n3 = tobase4(s3)
    if n2 == n3:
        print("YES")
    else:
        print("NO")
print ('END OF OUTPUT')