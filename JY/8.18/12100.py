import sys
from itertools import product
from copy import deepcopy
input = sys.stdin.readline

N = int(input())

board = [list(map(int, input().split())) for _ in range(N)]

def up(board):
    
    for i in range(N):
        temp = -1
        goto = [0, i]
        for j in range(N):
            if board[j][i] == 0:
                continue
            if temp==-1:
                temp = board[j][i]
                continue
            if temp == board[j][i]:
                board[goto[0]][goto[1]] =temp*2
                temp = -1
                goto[0] += 1
                continue
            if temp != board[j][i]:
                board[goto[0]][goto[1]] = temp
                temp = board[j][i]
                goto[0] += 1
        if temp != -1:
            board[goto[0]][goto[1]] = temp
            goto[0] += 1
        for k in range(goto[0], N):
            board[k][i] = 0
        
    return board
def down(board):
    
    for i in range(N):
        temp = -1
        goto = [N-1, i]
        for j in range(N-1, -1, -1):
            if board[j][i] == 0:
                continue
            if temp==-1:
                temp = board[j][i]
                continue
            if temp == board[j][i]:
                board[goto[0]][goto[1]] =temp*2
                temp = -1
                goto[0] -= 1
                continue
            if temp != board[j][i]:
                board[goto[0]][goto[1]] = temp
                temp = board[j][i]
                goto[0] -= 1
        if temp != -1:
            board[goto[0]][goto[1]] = temp
            goto[0] -= 1
        for k in range(goto[0], -1, -1):
            board[k][i] = 0
        
    return board
def left(board):
    
    for i in range(N):
        temp = -1
        goto = [i, 0]
        for j in range(N):
            if board[i][j] == 0:
                continue
            if temp==-1:
                temp = board[i][j]
                continue
            if temp == board[i][j]:
                board[goto[0]][goto[1]] =temp*2
                temp = -1
                goto[1] += 1
                continue
            if temp != board[i][j]:
                board[goto[0]][goto[1]] = temp
                temp = board[i][j]
                goto[1] += 1
        if temp != -1:
            board[goto[0]][goto[1]] = temp
            goto[1] += 1
        for k in range(goto[1], N):
            board[i][k] = 0
        
    return board
def right(board):
    
    for i in range(N):
        temp = -1
        goto = [i, N-1]
        for j in range(N-1, -1, -1):
            if board[i][j] == 0:
                continue
            if temp==-1:
                temp = board[i][j]
                continue
            if temp == board[i][j]:
                board[goto[0]][goto[1]] =temp*2
                temp = -1
                goto[1] -= 1
                continue
            if temp != board[i][j]:
                board[goto[0]][goto[1]] = temp
                temp = board[i][j]
                goto[1] -= 1
        if temp != -1:
            board[goto[0]][goto[1]] = temp
            goto[1] -= 1
        for k in range(goto[1], -1, -1):
            board[i][k] = 0
        
    return board



def b2048(li, board):
    temp = deepcopy(board)
    ret = 0
    for i in li:
        if i==1:
            temp = up(temp)
        elif i==2:
            temp = down(temp)
        elif i==3:
            temp = left(temp)
        else:
            temp = right(temp)
        temp = deepcopy(temp)
    for i in temp:
        for j in i:
            ret = max(ret, j)
    return ret

li = [1, 2, 3, 4]
li = product(li, repeat=5)
ans = 0
for i in li:
    ans = max(b2048(i, board), ans)
print(ans)
    
''' 
3
2 4 8
2 4 8
2 4 8

4
2 0 0 0
2 2 0 0
2 0 0 0
0 0 0 0

'''
