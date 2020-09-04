import sys

input = sys.stdin.readline

li = [0, 1, 2, 4] +[None]*20
def func(i):
    if li[i] != None:
        return li[i]
    else:
        li[i] = func(i-1)+func(i-2)+func(i-3)
        return li[i]

for _ in range(int(input())):
    k = int(input())
    print(func(k))