import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())

#relations = [list(map(int, input().split())) for _ in range(M)]
# graph = {i:[] for i in range(1, N+1)}
graph = [[] for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[b].append(a)
'''for i, j in relations:
    graph[j].append(i)'''
max_nums = []
max_cnt = 0

for i in range(1, N+1):
    queue = deque()
    queue.append(i)
    visit = [False]*(N+1)
    cnt = 0
    while queue:
        node = queue.popleft()
        cnt += 1
        for k in graph[node]:
            if not visit[k]:
                visit[k]=1
                queue.append(k)
    if cnt>max_cnt:
        max_nums = []
        max_nums.append(i)
        max_cnt = cnt
    elif cnt==max_cnt:
        max_nums.append(i)
        

for i in max_nums:
    print(i, end=' ')
print() 


'''
3 3
3 1
2 1
3 2
'''