def gcd(x, y): 
   while(y): 
       x, y = y, x % y   
   return x 

arr = [26000000, 11000000, 6000000]
# arr = [1,10,11]
myRes = 0
rr = 0
array = []

for res in range(6000000):
    g = arr[0] + res
    for x in arr:
        g = gcd(x + res, g)
    if myRes < g:
        myRes = g
        rr = res

print myRes, rr