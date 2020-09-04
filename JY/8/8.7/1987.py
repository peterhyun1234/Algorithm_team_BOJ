import sys

import copy
input = sys.stdin.readline
direction  = [[1, 0], [-1, 0], [0, 1], [0, -1]]

R, C = map(int, input().split())


board = [list(input().strip()) for _ in range(R)]

stack = []

stack.append([[0,0], set([]), 1])
visit = [[False]*C for _ in range(R)]
ans = 0
while stack:
    loc, s, count = stack.pop()
    x, y = loc
    # if board[x][y] not in s:
    s.add(board[x][y])
    ans = max(ans, count)
    for i, j in direction:
        a = x+i
        b = y+j
        if 0<=a<R and 0<=b<C and board[a][b] not in s:
            s = copy.copy(s)
            stack.append([[a,b], s, count+1])
print(ans)

'''
10 10
ASWERHGCFH
QWERHDLKDG
ZKFOWOHKRK
SALTPWOKSS
BMDLKLKDKF
ALSKEMFLFQ
GMHMBPTIYU
DMNKJZKQLF
HKFKGLKEOL
OTOJKNKRMW
'''