
a = raw_input()

a = int(a, 16) 
b = a%(pow(2, 8))
g = (a/(pow(2, 8))) % (pow(2, 8))
r = (a/(pow(2, 16))) % (pow(2, 16))

print r, g, b