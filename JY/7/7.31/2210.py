import sys
from collections import deque

input = sys.stdin.readline

digit_li = [input().split() for _ in range(5)]

start_li = [[x,y] for x in range(5)
                    for y in range(5)]

direction = [[1, 0], [0, -1], [-1, 0], [0, 1]]

s = set()

for sx, sy in start_li:
    queue = deque()
    queue.append(([sx,sy], digit_li[sx][sy],1))
    while queue:
        node = queue.popleft()
        [x, y], num, times  = node
        if times == 6:
            s.add(num)
            continue
        for i, j in direction:
            a = x+i
            b = y+j
            if a>=0 and b>=0 and a<5 and b<5:
                queue.append(([a,b],num+digit_li[a][b], times+1))

print(len(s))
