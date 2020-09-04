import sys
import heapq

input = sys.stdin.readline

N, K = map(int, input().split())

li_j = []
li_b = []
arr = []
count = 0
for _ in range(N):
    li_j.append(list(map(int, input().split())))

for _ in range(K):
    li_b.append(int(input()))

li_j.sort()
li_b.sort()

j = 0

for i in li_b:
    ma = 0
    while j<N and li_j[j][0]<=i:
        heapq.heappush(arr, -li_j[j][1])
        ma = max(ma, li_j[j][1])
        j += 1
        if j==N:
            break
    if arr:
        if ma < -arr[0]:
            ma = -heapq.heappop(arr)
        else:
            heapq.heappop(arr)
    count += ma
    
        

print(count)