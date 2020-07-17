import sys

input = sys.stdin.readline

mi, ma = map(int, input().split())

li_ex= [False] * (ma-mi+1)

po_mi = mi**(1/2)

if (int(po_mi) - po_mi) == 0:
	po_mi = int(po_mi)
else:
	po_mi = int(po_mi)+1

po_ma = int(ma**(1/2))


for i in range(2, po_ma+1):
	i2 = i**2
	for j in range(mi//i2, 1000000000000):
		if i2*j<mi:
			continue
		elif i2*j>ma:
			break
		else:
			li_ex[i2*j-mi] = True
	

print(li_ex.count(False))


