import sys
from itertools import combinations
input = sys.stdin.readline

graph = []

populations = [0]
N = int(input())
e_num = 0
ans = 10000000

populations.extend(list(map(int, input().split())))
for i in range(N):
    en, *temp_li = list(map(int, input().split()))
    graph.append(temp_li)
    e_num += en

def check(area):
    visit = {i:False for i in area}
    ret = True
    stack = []
    stack.append(area[0])
    while stack:
        node = stack.pop()
        if node in visit and not visit[node]:
            visit[node] = True
            stack.extend(graph[node-1])
    for i in visit:
        if not visit[i]:
            ret = False
    
    return ret

for i in range(1, round(N/2)+1):
    areas = list(combinations(range(1,N+1), i))
    
    for area in areas:
        remain_area = list(range(1, N+1))
        for j in area:
            remain_area.remove(j)
            
        if check(area) and check(remain_area):
            sum_area = 0
            sum_remain_area = 0
            for k in area:
                sum_area += populations[k]
            for k in remain_area:
                sum_remain_area += populations[k]
            ans = min(ans, abs(sum_area-sum_remain_area))
if ans==10000000:
    print(-1)
else:
    print(ans)