from collections import defaultdict
from collections import deque

def solution(n, edge):
    ans = 0
    max_cnt = -1
    graph = defaultdict(list)
    for i,j in edge:
        graph[i].append(j)
        graph[j].append(i)
    visit = [False]*(n+1)
    queue = deque()
    queue.append([1, 0])
    visit[1] = True
    while queue:
        node, cnt = queue.popleft()
        
        if max_cnt<cnt:
            max_cnt = cnt
            ans = 1
        elif max_cnt==cnt:
            ans += 1
        for i in graph[node]:
            if not visit[i]:
                visit[i] = True
                queue.append([i, cnt+1])
    
    return ans
print(solution(6,[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))