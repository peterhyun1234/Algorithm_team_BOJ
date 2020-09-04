import sys

input = sys.stdin.readline

sum = 0
li = []
N = input()
N = N[:-1]
s = ''
for i in N:
    a = int(i)
    sum += a
    li.append(a)

if sum%3==0 and 0 in li:
    li.sort(reverse=True)
    for i in li:
        s += str(i)
    print(s)

else:
    print(-1)