import sys
from collections import deque

input = sys.stdin.readline
knight_go = [[2, 1], [1, 2], [-1, -2], [-2, -1], \
             [-1, 2], [-2, 1], [1, -2], [2, -1]]
T = int(input())

for _ in range(T):
    l = int(input())
    coor1 = list(map(int, input().split()))
    coor2 = list(map(int, input().split()))

    queue = deque()
    visit = [[False]*l for i in range(l)]
    queuearr = [[False]*l for i in range(l)]
    d = [[None]*l for i in range(l)]
    d[coor1[0]][coor1[1]] = 0
    
    queue.append(coor1)
    
    while queue:
        node = queue.popleft()

        x, y = node
        
        if node == coor2:
            print(d[x][y])
            break
        if not visit[x][y]:
            visit[x][y] = True
            for i, j in knight_go:
                a = x+i
                b = y+j
                if a>=0 and b>=0 and a<l and b<l :
                    if not queuearr[a][b]:
                        queuearr[a][b] = True
                        queue.append([a, b])
                        d[a][b] = d[x][y] + 1
