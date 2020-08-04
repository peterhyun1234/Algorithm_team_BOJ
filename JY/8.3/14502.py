import sys
from itertools import product
from copy import deepcopy
input = sys.stdin.readline

N, M = map(int, input().split())

li = [list(map(int, input().split())) for _ in range(N)]
direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
def virus(graph):
    temp_graph = deepcopy(graph)
    s_point = []
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 2:
                s_point.append([i, j])
    
    stack = []
    visit = [[False]*M for _ in range(N)]
    while s_point:
        stack.append(s_point.pop())
        while stack:
            x, y = stack.pop()
            if (not visit[x][y]) and (graph[x][y] != 1):
                visit[x][y] = True
                temp_graph[x][y] = 2
                for i, j in direction:
                    a = x+i
                    b = y+j
                    if a>=0 and a<N and b>=0 and b<M:
                        stack.append([a, b])
    return temp_graph                         

def find_zero(graph):
    count = 0
    for i in range(N):
        for j in range(M):
            if graph[i][j]==0:
                count += 1
    return count

loc = list(product(range(N), range(M)))
len_loc = len(loc)
count_li = []
for i in range(len_loc-2):
    for j in range(i+1, len_loc-1):
        for k in range(j+1, len_loc):
            x1, y1 = loc[i]
            x2, y2 = loc[j]
            x3, y3 = loc[k]
            if li[x1][y1]==0 and li[x2][y2]==0 and li[x3][y3]==0:
                temp_graph = deepcopy(li)
                temp_graph[x1][y1] = 1
                temp_graph[x2][y2] = 1
                temp_graph[x3][y3] = 1
                count_li.append(find_zero(virus(temp_graph)))
                

print(virus(li))
print(li)
print(max(count_li))

'''
5 5
2 0 0 0 1
0 0 0 1 0
0 0 1 0 0
0 1 0 0 0
1 0 0 0 0

'''