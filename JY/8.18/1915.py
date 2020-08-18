import sys
import copy


input = sys.stdin.readline
n, m = map(int, input().split())
li = [list(input().strip()) for _ in range(n)]

size = 2
area = 0
ans = 1
coor_li = []
for i in range(n):
    for j in range(m):
        if li[i][j] == '1':
            coor_li.append([i,j])
while coor_li:
    temp_coor = []
    for i, j in coor_li:
        area = 0
        for a in range(size):
            if i+a<n and j+size-1<m:
                if li[i+a][j+size-1] == '1':
                    area += 1
        for b in range(size):
            if i+size-1<n and j+b<m:
                if li[i+size-1][j+b] == '1':
                    area += 1
        if  area == size*2:
            ans = size**2
            temp_coor.append([i, j])
    
    del coor_li
    coor_li = copy.copy(temp_coor)
    del temp_coor
    size += 1
    

print(ans)
