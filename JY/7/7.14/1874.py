import sys
input = sys.stdin.readline

n = int(input())

stack = [0]
opli = []
idx = 0
li = []

for _ in range(n):
    li.append(int(input()))
i = 1
while idx<n:
    if i>n+1:
        break

    if stack[-1]==li[idx]:
        stack.pop()
        opli.append('-')
        idx += 1
    else:
        stack.append(i)
        opli.append('+')
        i += 1
if i>n+1:
    print('NO')
else:
    for j in opli:
        print(j)