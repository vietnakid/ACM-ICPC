while True:
    try:
        n = input()
        if n == '0.00':
            break
        n = float(n)
        cnt = 0
        sum = 0
        while sum < n:
            cnt += 1
            sum += 1./float(cnt+1)
        print cnt, 'card(s)'
    except:
        break