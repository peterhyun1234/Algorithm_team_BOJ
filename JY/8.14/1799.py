'''import sys
from itertools import combinations

input = sys.stdin.readline

N = int(input())

board = [list(map(int, input().split())) for _ in range(N)]
ac_li = []
blackac_li = []
whiteac_li = []
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            if (i+j)%2==0:
                blackac_li.append([i, j])
            else:
                whiteac_li.append([i, j])

def check(li):
    l = len(li)
    for i in range(l):
        for j in range(i+1, l):
            x1, y1 = li[i]
            x2, y2 = li[j]
            if abs(x1-x2) == abs(y1-y2):
                return False
    return True

def dfs(li, cnt):
    l = len(li)
    latest_li = []
    stack = []
    stack.extend(list(range(cnt)))

    while stack:
        if check(stack):
            return True
        else:
            node = stack.pop()
            node
        
'''
def check(idx): 
    c = idx%2 
    i, j = idx//n, idx%n 

    for d in range(4): 
        x, y = i+dx[d], j+dy[d] 
        while 0<=x<n and 0<=y<n: 
            if visited[x*n + y]: 
                return False 
            x += dx[d] 
            y += dy[d] 
    return True 

def dfs(idx, c, cnt): 
    if n*n-idx+1+cnt <= ans[c] or idx >= n*n: 
        return 

    ans[c] = max(ans[c], cnt) 
    x, y = idx//n, idx%n 
    j = y 
    for i in range(x, n): 
        while j < n: 
            v = i*n + j 
            if not visited[v] and chess[i][j] == 1 and check(v): 
                visited[v] = True 
                dfs(v, c, cnt+1) 
                visited[v] = False 
            j += 2 
        j = (c+1)%2 if i%2 == 0 else c

n = int(input()) 
chess = [list(map(int, input().split())) for _ in range(n)] 
dx, dy = [1, -1, 1, -1], [1, 1, -1, -1] 
visited = [False] * (n**2) 
ans = [0, 0] # 짝수는 0, 홀수는 1 
dfs(0, 0, 0) 
dfs(1, 1, 0) 
print(sum(ans))



'''

bb_num = 1

while True:
    is_break = False
    for i in combinations(blackac_li, bb_num):
        if check(i):
            bb_num += 1
            is_break = True
            break
    if not is_break:
        break
wb_num =1
while True:
    is_break = False
    for i in combinations(whiteac_li, wb_num):
        if check(i):
            wb_num += 1
            is_break = True
            break
    if not is_break:
        break

       

print((bb_num-1)+(wb_num-1))
    

'''