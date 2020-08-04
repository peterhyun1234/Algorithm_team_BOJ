import sys
input = sys.stdin.readline

N = int(input())

li = [list(input().strip()) for _ in range(N)]
direction = [(1,0), (-1,0), (0, 1), (0, -1)]
s_point = []
stack = []
li_count = []
visit = [[False]*N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if li[i][j]=='1':
            s_point.append([i, j])


while s_point:
    stack.append(s_point.pop())
    count = 0
    while stack:
        node = stack.pop()
        x, y = node
        if not visit[x][y] and li[x][y] == '1':
            visit[x][y] = True
            count += 1
            for i, j in direction:
                a = x+i
                b = y+j
                if a>=0 and a<N and b>=0 and b<N:
                    stack.append([a, b])
    if count:
        li_count.append(count)    
print(len(li_count))
for i in sorted(li_count):
    print(i)
        
