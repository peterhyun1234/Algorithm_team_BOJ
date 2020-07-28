import sys
import heapq
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    M = int(input())
    li = []
    k = 0
    for _ in range(M//10+1):
        li.extend(list(map(int, input().split())))
    print(M//2+1)
    for i in range(M):
        if i%2 == 0:
            temp_li = sorted(li[:i+1])
            print(temp_li[i//2], end=' ')
            if k//10!=(k+1)//10:
                print()
            k +=1
    print()