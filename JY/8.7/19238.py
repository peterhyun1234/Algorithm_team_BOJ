import sys
from collections import deque
input = sys.stdin.readline

N, M, f = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(N)]

taxi_loc = list(map(int, input().split()))
taxi_loc = [taxi_loc[0]-1, taxi_loc[1]-1]
pd_info = dict()
d = [[1, 0], [-1, 0], [0, 1], [0, -1]]

for _ in range(M):
    px, py, dx, dy = list(map(int, input().split()))
    
    pd_info[f"{px-1} {py-1}"]=[dx-1,dy-1]

def find_d(from_loc, to_loc):
    fx, fy = from_loc
    tx, ty = to_loc
    visit = [[False]*N for _ in range(N)]

    queue = deque()

    queue.append([fx, fy, 0])

    while queue:
        x, y, count = queue.popleft()

        if not visit[x][y] and board[x][y]==0:
            visit[x][y] = True
            if [x,y] == [tx, ty]:
                return count
            for i, j in d:
                a = x+i
                b = y+j
                if 0<=a<N and 0<=b<N:
                    queue.append([a, b, count+1])
can_arr = True
while pd_info:
    remove = []
    
    pas_d = 10000
    for p_loc in pd_info.keys():
        p_loc = list(map(int, p_loc.split()))
        dis = find_d(taxi_loc, p_loc)
        if type(dis)!=int:
            print(-1)
            exit(0)
        if pas_d>dis:
            remove = []
            remove.append(p_loc)
            pas_d = dis
        elif pas_d==dis:
            remove.append(p_loc)
    remove.sort(key = lambda x: x[1])
    remove.sort(key = lambda x: x[0])
    pas = remove[0]
    des = pd_info[f"{pas[0]} {pas[1]}"]
    des_d = find_d(pas, des)
    if type(des_d)!=int:
        print(-1)
        exit(0)
    f -= pas_d+des_d
    if f<0:
        can_arr =False
        break
    f += des_d*2
    taxi_loc = des
    
    del pd_info[f"{pas[0]} {pas[1]}"]

if can_arr:
    print(f)
else:
    print(-1)
        
'''
6 4 15
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 1 0 0
6 5
2 2 5 6
5 4 1 6
4 2 3 5
1 6 5 4

ans 20
'''