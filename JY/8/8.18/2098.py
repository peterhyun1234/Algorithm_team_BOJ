import sys

N = int(input())

li = [list(map(int, input().split())) for _ in range(N)]

dp = [[None]*(1<<N) for _ in range(N)]

def find_path(last, visited):
    if visited==(1<<N)-1:
        return li[last][0] or float('inf')
    if dp[last][visited]:
        return dp[last][visited]

    tmp = float('inf')
    for city in range(N):
        if visited & (1<<city) == 0 and li[last][city] != 0:
            tmp = min(tmp, find_path(city, visited | (1<<city)) + li[last][city])
    
    dp[last][visited] = tmp
    return tmp

print(find_path(0, 1))
    
'''
import sys
 
N=int(sys.stdin.readline())
W=[]
INF=sys.maxsize
for _ in range(N):
    W.append(list(map(int,sys.stdin.readline().split())))
DP=[[None]*(1<<N) for _ in range(N)]
 
def find_path(last,visited):#현재위치
    if visited == (1<<N)-1:  # 모두 방문햇다면
        return W[last][0] or float('inf')  # 0으로 가는방법 반환 없으면 INF반환
 
    if DP[last][visited] is not None:  # 이미 계산되어잇다면
        return DP[last][visited]  # 있는값 반환
 
    tmp=float('inf')
    for city in range(N):#모든 도시에서
        if visited & (1 << city) == 0 and W[last][city] != 0:#아직 방문하지 않았고 cur->i로 가는길이 있다면
            tmp=min(tmp,
                    find_path(city,visited | (1<<city)) + W[last][city])
    DP[last][visited]=tmp
    return tmp
 
 
print(find_path(0,1))


'''


'''
import sys 
def move(now, depth): 
    global charge, ans 
    if depth == n: 
        if path[now][0] > 0: 
            ans = min(ans, charge + path[now][0]) 
        return 
    visit[now] = 1 

    for l in link[now]: 
        if not visit[l]: 
            charge += path[now][l] 
            move(l, depth+1) 
            charge -= path[now][l] 
    visit[now] = 0 

n = int(sys.stdin.readline()) 
path = [list(map(int, sys.stdin.readline().split())) for _ in range(n)] 
visit = [0] * n 
link = {} 
charge, ans = 0, 10**7 
for i in range(n): 
    link[i] = [] 
    for j in range(n): 
        if path[i][j] > 0: 
            link[i].append(j) 
move(0, 1) 
print(ans)
'''