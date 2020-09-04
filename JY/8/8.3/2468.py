import sys

input = sys.stdin.readline

N = int(input())
area = [list(map(int, input().split())) for _ in range(N)]
k_li = []
direction = [(1,0), (-1,0), (0, 1), (0, -1)]
for k in range(1, 100):
    flood = [[True]*N for _ in range(N)]
    visit = [[False]*N for _ in range(N)]
    s_point = []
    li_count = []
    stack = []
    for i in range(N):
        for j in range(N):
            if area[i][j]>k-1:
                flood[i][j]=False
                s_point.append([i, j])

    while s_point:
        stack.append(s_point.pop())
        count = 0
        while stack:
            node = stack.pop()
            x, y = node
            if not visit[x][y] and not flood[x][y]:
                visit[x][y] = True
                count += 1
                for i, j in direction:
                    a = x+i
                    b = y+j
                    if a>=0 and a<N and b>=0 and b<N:
                        stack.append([a, b])
        if count:
            li_count.append(count)
    if len(li_count):
        k_li.append(len(li_count))

print(max(k_li))