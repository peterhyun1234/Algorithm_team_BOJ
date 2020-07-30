import sys
import heapq

input = sys.stdin.readline
N = int(input())

ans_li = []
arr = []
li = list(map(int, input().split()))
arr = li[:]
for _ in range(N-1):
    li = list(map(int, input().split()))
    for i in li:
        heapq.heappush(arr, i)
    for _ in range(N):
        heapq.heappop(arr)

print(arr[0])


