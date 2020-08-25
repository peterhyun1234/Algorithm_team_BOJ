import sys
import heapq

input = sys.stdin.readline

N, M = map(int, input().split())
T_li = []
least_end = float('inf')
for _ in range(N):
    test_t = int(input())
    T_li.append(test_t)
    least_end = min(least_end, test_t)

start, end = 0, least_end*M
ans = 0
while start<end:
    mid = (start+end)//2
    count = 0
    for i in T_li:
        count += mid//i
   
    if count>=M:
        end = mid
    else:
        start = mid+1


print(end)