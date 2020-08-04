import sys

input = sys.stdin.readline

N = int(input())

li = [list(input().strip()) for _ in range(N)]
direction = [[1, 0], [-1, 0], [0, -1], [0, 1]]
green_li = [[False]*N for _ in range(N)]
red_li = [[False]*N for _ in range(N)]
blue_li = [[False]*N for _ in range(N)]
greenred_li = [[False]*N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if li[i][j] == 'G':
            green_li[i][j] = True
            greenred_li[i][j] = True
        elif li[i][j] == 'R':
            red_li[i][j] = True
            greenred_li[i][j] = True
        else:
            blue_li[i][j] = True



def dfs(graph):
    s_point = []
    for i in range(N):
        for j in range(N):
            if graph[i][j]:
                s_point.append([i, j])
    visit = [[False]*N for _ in range(N)]
    count = 0
    while s_point:
        stack = []
        stack.append(s_point.pop())
        flag = False
        while stack:
            x, y = stack.pop()
            if not visit[x][y]:
                visit[x][y] = True
                flag = True
                for i, j in direction:
                    a = x+i
                    b = y+j
                    if a>=0 and a<N and b>=0 and b<N and graph[a][b]:
                        stack.append([a, b])
        if flag:
            count += 1

    return count

print(dfs(green_li)+dfs(red_li)+dfs(blue_li), end=' ')
print(dfs(greenred_li)+dfs(blue_li))
