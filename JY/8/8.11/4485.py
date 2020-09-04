import sys
from collections import deque
import heapq

input = sys.stdin.readline

case_num = 1
directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
while True:
    N = int(input())
    if not N:
        break
    cave = [list(map(int, input().split())) for _ in range(N)]
    val_map = [[10000000]*N for _ in range(N)]
    visit = [[False]*N for _ in range(N)]
    heaparr = []
    heapq.heappush(heaparr, [0, 0, 0])
    while heaparr:
        val, x, y  = heapq.heappop(heaparr)
        if not visit[x][y]:
            visit[x][y] = True
            val_map[x][y] = min(val_map[x][y], val+cave[x][y])
            for direction in directions:
                i, j = direction
                a = x+i
                b = y+j
                if 0<=a<N and 0<=b<N:
                    heapq.heappush(heaparr, [val_map[x][y], a, b])
    
    print(f'Problem {case_num}: {val_map[N-1][N-1]}')
    case_num += 1
    
        