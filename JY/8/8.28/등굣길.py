from collections import deque

d = [[1,0], [-1, 0], [0, 1], [0, -1]]

def solution(m, n, puddles):
    ans = 0
    dp = [[[1000000, 0] for _ in range(m+1)] for _ in range(n+1)]
    puddles_map = [[False]*(m+1) for _ in range(n+1)]
    for x,y in puddles:
        puddles_map[x][y] = True
    
    queue = deque()
    queue.append([1,1,1])
    #print(dp)
    
    while queue:
        x, y, cnt = queue.popleft()
        if dp[x][y][0]<cnt:
            continue
        elif dp[x][y][0]>cnt:
            dp[x][y][0] = cnt
            dp[x][y][1] = 1
        elif dp[x][y][0]==cnt:
            dp[x][y][1] += 1
            dp[x][y][1] %1000000007
        for i, j in d:
            a = x+i
            b = y+j
            if 0<a<n+1 and 0<b<m+1 and puddles_map[a][b]!=True:
                queue.append([a,b, (cnt+1)])
                
    ans = dp[n][m][1]%1000000007
    return ans

solution(4,3,[[2,2]])