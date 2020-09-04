import sys

input = sys.stdin.readline

N = int(input())

li = [int(input()) for _ in range(N)]
li.sort(reverse=True)
d = []
while li:
    d.append(li[-1]*len(li))
    li.pop()
print(max(d))
