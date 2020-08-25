import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
bridges = dict()
max_w = 0
for _ in range(M):
    a, b, c = map(int, input().split())
    if a not in bridges:
        bridges[a] = dict()
    if b not in bridges[a]:
        bridges[a][b] = 0
    if b not in bridges:
        bridges[b] = dict()
    if a not in bridges[b]:
        bridges[b][a] = 0
    bridges[a][b] = max(bridges[a][b], c)
    bridges[b][a] = max(bridges[b][a], c)
    max_w = max(max_w, c)

islandA, islandB = map(int, input().split())
start = 1
end = max_w
ans = start
while start<=end:
    mid = (start+end)//2
    can_arr = False
    visit = [False]*(N+1)
    queue = deque()
    queue.append([islandA, float('inf')])
    while queue:
        node, temp_w = queue.popleft()
        if temp_w<mid:
            continue
        if node == islandB:
            can_arr = True
            break
        if not visit[node]:
            visit[node] = True
            for i, k in bridges[node].items():
                queue.append([i, k])
    if not can_arr:
        end = mid-1
    else:
        ans = mid
        start = mid+1

print(ans)
            

    