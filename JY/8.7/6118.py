import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())

li = [list(map(int, input().split())) for _ in range(M)]

graph = [[] for _ in range(N+1)]

for i in li:
    fromV, toV = i
    graph[fromV].append(toV)
    graph[toV].append(fromV)

queue = deque()

queue.append([1, 0])
visit = [False]*(N+1)
ans_li = []
while queue:
    node, count = queue.popleft()

    if visit[node] == False:
        visit[node] = True
        ans_li.append([node, count])
        for i in graph[node]:
            queue.append([i, count+1])
            
last = ans_li[-1][1]
tempi = 0
count = 0
mi = 1000000
for i in ans_li:
    if i[1]==last:
        count += 1
        mi = min(mi, i[0])
print(mi, last, count)