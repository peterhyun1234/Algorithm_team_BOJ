import sys
from collections import deque
input = sys.stdin.readline
N, M = map(int, input().split())
maze = [list(input().strip()) for _ in range(N)]
start = []
for i in range(N):
    for j in range(M):
        if maze[i][j] == '0':
            start = [i-1, j-1]
            break
    if start:
        break


d = [[1,0], [0, 1], [-1, 0], [0, -1]]

queue = deque()

queue.append(start)

while queue: