import sys
from itertools import combinations
input = sys.stdin.readline

N, S = map(int, input().split())
li = list(map(int, input().split()))
count = 0
for i in range(1, N+1):
    temp = combinations(li, i)
    for j in temp:
        if sum(j)==S:
            count +=1

print(count)