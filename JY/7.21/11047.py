import sys

input = sys.stdin.readline

N, money = map(int, input().split())

li = []

for _ in range(N):
    li.append(int(input()))

count = 0

for i in reversed(li):
    if money >= i:
        a = money // i
        money -= a*i
        count += a

print(count)