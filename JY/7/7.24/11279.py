import sys
import heapq

input = sys.stdin.readline

N = int(input())

li = [int(input()) for _ in range(N)]

arr = []

for i in li:
    if i == 0:
        if not arr:
            print(0)
        else:
            print(heapq.heappop(arr)[1])
    else:
        heapq.heappush(arr, (abs(i), i))
        