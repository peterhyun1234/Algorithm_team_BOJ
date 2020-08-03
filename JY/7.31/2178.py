import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())

maze = [list(input().strip()) for _ in range(N)]
visit = [[False]*M for _ in range(N)]

direction = [[1, 0], [0, 1], [-1, 0], [0, -1]]

queue = deque()
queue.append(([0,0],1))

while queue:
    [x, y], count = queue.popleft()
    
    if [x,y] == [N-1, M-1]:
        print(count)
        break
    if not visit[x][y]:
        visit[x][y] = True
        for i, j in direction:
            a = x + i
            b = y + j
            if a>=0 and b>=0 and a<N and b<M:
                if maze[a][b] == '1':
                    queue.append(([a, b], count+1))


    
    
