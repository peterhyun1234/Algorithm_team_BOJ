from collections import defaultdict

def solution(n, results):
    ans = 0
    win = defaultdict(list)
    lose = defaultdict(list)
    for i, j in results:
        win[i].append(j)
        lose[j].append(i)
        
    for i in range(1, n+1):
        stack = []
        stack.append(i)
        visit = [False]*(n+1)
        cnt = 0
        while stack:
            node = stack.pop()
            for j in win[node]:
                if not visit[j]:
                    cnt += 1
                    visit[j] = True
                    stack.append(j)
        stack = []
        stack.append(i)
        visit = [False]*(n+1)
        while stack:
            node = stack.pop()
            for j in lose[node]:
                if not visit[j]:
                    cnt += 1
                    visit[j] = True
                    stack.append(j)
        if cnt == (n-1):
            ans += 1
        
    
    return ans