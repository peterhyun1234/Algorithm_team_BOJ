'''
import sys

N = input().strip()
M = int(input())

li = list(map(int, input().split()))

li10 = {i: True for i in range(10)}

mi = 0
ma = 0

for i in li:
    li10[i] = False
for i in range(10):
    if li10[i] == True:
        mi = i
        break
for i in range(10):
    if li10[i] == True:
        ma = i

mi = str(mi)
ma = str(ma)
ans = abs(int(N)-100)
if M==10:
    print(ans)
    exit()

upper = ''
lower = ''
count = 0
last_num = 0
for num in N:
    i = int(num)
    if li10[i] == True:
        upper += num
        lower += num
        count += 1
    else:
        last_num = i
        break
mi1 = 0
ma1 = 0

for i in range(last_num, 10):
    if li10[i] == True:
        mi1 = i
        break
for i in range(last_num):
    if li10[i] == True:
        ma1 = i

mi1 = str(mi1)
ma1 = str(ma1)
        
count += len(N)-len(lower)

upper += mi1+mi*(len(N)-len(upper)-1)
lower += ma1+ma*(len(N)-len(lower)-1)

ans = min(ans, abs(int(N)-int(upper))+count, abs(int(N)-int(lower))+count)

print(ans)
'''
from itertools import product

N = input().strip()
M = int(input())

li = list(map(int, input().split()))

ans = abs(int(N)-100)
li_10 = list(range(0,10))

for i in li:
    li_10.remove(i)
len_N = len(N)

li_all = product(map(str,li_10), repeat=len_N)

count = 100000000
for arr in li_all:
    s = ''.join(arr)
    count = min(count, abs(int(N)-int(s))+len_N)

if len(li_10)>0:
    upper = '0'
    if li_10[0]!=0:
        upper = str(li_10[0])*(len_N+1)
    elif len(li_10)>1:
        upper = str(li_10[1])+str(0)*(len_N)

    lower = '0'
    if li[-1] != 0 and len_N>1:
        lower = str(li_10[-1])*(len_N-1)

    count = min(count, abs(int(upper)-int(N))+len_N+1, abs(int(lower)-int(N))+len_N-1)
ans = min(ans, count)

print(ans)

