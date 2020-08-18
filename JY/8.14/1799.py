import sys
from itertools import combinations

input = sys.stdin.readline

N = int(input())

board = [list(map(int, input().split())) for _ in range(N)]
ac_li = []
blackac_li = []
whiteac_li = []
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            if (i+j)%2==0:
                blackac_li.append([i, j])
            else:
                whiteac_li.append([i, j])

def check(li):
    l = len(li)
    for i in range(l):
        for j in range(i+1, l):
            x1, y1 = li[i]
            x2, y2 = li[j]
            if abs(x1-x2) == abs(y1-y2):
                return False
    return True

def dfs(li, cnt):
    l = len(li)
    
    stack = [[1]]
    stack.extend(list(range(cnt)))

    while stack:
        if check(stack):
            return True
        else:
            node = stack.pop()
            node
        



'''

bb_num = 1

while True:
    is_break = False
    for i in combinations(blackac_li, bb_num):
        if check(i):
            bb_num += 1
            is_break = True
            break
    if not is_break:
        break
wb_num =1
while True:
    is_break = False
    for i in combinations(whiteac_li, wb_num):
        if check(i):
            wb_num += 1
            is_break = True
            break
    if not is_break:
        break

       

print((bb_num-1)+(wb_num-1))
    

'''