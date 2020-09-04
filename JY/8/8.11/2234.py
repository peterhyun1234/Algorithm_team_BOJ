import sys
input = sys.stdin.readline

n, m = map(int, input().split())

castle_walls = [list(map(int, input().split())) for _ in range(m)]
visit = [[False]*n for _ in range(m)]
directions = [[0, -1], [-1, 0], [0, 1], [1, 0]]

castle_rooms = [[None]*n for _ in range(m)]

room_num = 0

room_info = dict()
max_room = 0

def wherecango(i, j):
    wall = castle_walls[i][j]
    ret_li = []
    for i in range(4):
        if wall&1==0:
            ret_li.append(i)
        wall = wall>>1
    return ret_li

for i in range(m):
    for j in range(n):
        if not visit[i][j]:
            stack = []
            count = 0
            stack.append([i, j])
            while stack:
                x, y = stack.pop()

                if not visit[x][y]:
                    visit[x][y] = True
                    castle_rooms[x][y] = room_num
                    count += 1
                    
                    for k in wherecango(x,y):
                        dx, dy = directions[k]
                        a = x+dx
                        b = y+dy
                        stack.append([a,b])
            
            room_info[room_num] = count
            max_room = max(max_room, count)
            room_num += 1
    
print(room_num)
print(max_room)
max_plus = 0
for x in range(m):
    for y in range(n):
        for i, j in directions:
            a = x+i
            b = y+j
            
            if 0<=a<m and 0<=b<n:
                room1 = castle_rooms[x][y]
                room2 = castle_rooms[a][b]
                if room1 != room2:
                    max_plus = max(max_plus, room_info[room1]+room_info[room2])
print(max_plus)
            
                
                    

        


    