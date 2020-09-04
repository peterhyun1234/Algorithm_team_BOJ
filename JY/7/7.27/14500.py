import sys

input = sys.stdin.readline
N, M = map(int, input().split())
li = []
a, b, c, d, e = 0, 0, 0, 0, 0
for _ in range(N):
    li.append(list(map(int, input().split())))

for i in range(N):
    for j in range(M-3):
        a = max(li[i][j]+li[i][j+1]+li[i][j+2]+li[i][j+3], a)
        
for i in range(N-3):
    for j in range(M):
        b = max(li[i][j]+li[i+1][j]+li[i+2][j]+li[i+3][j], b)

for i in range(N-2):
    for j in range(M-1):
        c = max(li[i][j]+li[i][j+1]+li[i+1][j]+li[i+2][j], #0
                li[i][j+1]+li[i+1][j+1]+li[i+2][j+1]+li[i+2][j],#o
                li[i][j]+li[i+1][j]+li[i+2][j]+li[i+2][j+1], #o
                li[i][j]+li[i][j+1]+li[i+1][j+1]+li[i+2][j+1], #o
                li[i][j]+li[i+1][j]+li[i+1][j+1]+li[i+2][j+1],
                li[i][j+1]+li[i+1][j]+li[i+1][j+1]+li[i+2][j],
                li[i][j]+li[i+1][j]+li[i+1][j+1]+li[i+2][j],
                li[i][j+1]+li[i+1][j]+li[i+1][j+1]+li[i+2][j+1],
                c,
                )
            

for i in range(N-1):
    for j in range(M-2):
        d = max(li[i][j]+li[i+1][j]+li[i+1][j+1]+li[i+1][j+2],
                li[i+1][j]+li[i+1][j+1]+li[i+1][j+2]+li[i][j+2],
                li[i][j]+li[i][j+1]+li[i][j+2]+li[i+1][j+2],
                li[i][j]+li[i][j+1]+li[i][j+2]+li[i+1][j],
                li[i][j]+li[i][j+1]+li[i][j+2]+li[i+1][j+1],
                li[i][j+1]+li[i+1][j]+li[i+1][j+1]+li[i+1][j+2],
                li[i][j]+li[i][j+1]+li[i+1][j+1]+li[i+1][j+2],
                li[i+1][j]+li[i+1][j+1]+li[i][j+1]+li[i][j+2],
                d
        )


for i in range(N-1):
    for j in range(M-1):
        e = max(li[i][j]+li[i+1][j]+li[i][j+1]+li[i+1][j+1],e)


print(max(a,b,c,d,e))
