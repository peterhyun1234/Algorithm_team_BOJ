from collections import defaultdict

def solution(n, computers):
    ans = 0
    graph = defaultdict(list)    
    for i in range(n):
        for j in range(i+1, n):
            if computers[i][j]==1:
                graph[i].append(j)
                graph[j].append(i)
    visit = [False]*n
    for i in range(n):
        if visit[i]:
            continue
        ans += 1
        stack = []
        stack.append(i)
        while stack:
            node = stack.pop()
            for j in graph[node]:
                if not visit[j]:
                    visit[j]=True
                    stack.append(j)
    
    
    return ans