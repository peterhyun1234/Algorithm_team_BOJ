import sys
input = sys.stdin.readline

N, M = map(int, input().split())
r, c, d1 = map(int, input().split())
directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]
room = [list(map(int, input().split())) for _ in range(N)]
cleaned = [[False]*M for _ in range(N)]

stack = []

stack.append([r, c, d1])
z = 0
while stack:
    x, y, d = stack.pop()
    can_go = False
    cleaned[x][y] = True
    
    for _ in range(5):
        d = (d-1)%4
        i, j = directions[d]
        a = x+i
        b = y+j
        if 0<=a<N and 0<=b<M:
            if room[a][b]==0 and cleaned[a][b]==False:
                stack.append([a,b,d])
                can_go = True
                break     

    if not can_go:
        d = (d+1)%4
        next_d = (d+2)%4
        i, j = directions[next_d]
        a = x+i
        b = y+j
        if 0<=a<N and 0<=b<M:
            if room[a][b]==0:
                stack.append([a,b,d])
    
                
count = 0

for i in range(N):
    for j in range(M):
        if cleaned[i][j]:
            count+=1

print(count)



        

    

