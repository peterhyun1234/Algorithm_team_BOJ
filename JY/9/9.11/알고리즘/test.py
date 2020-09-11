s = set(((1,2), (2, 3)))
def func(a):
    set(a)
    a.add((3,4))
func(s)


print(s)


'''
func(li)
print(li)
import sys
sys.setrecursionlimit(2000)
ans = 200
d = [[0,1],[1,0],[0,-1],[-1,0]]

def solution(board):
    bs = len(board)
    global ans 
    ans = bs*3
    def dfs(r1, r2, n):
        global ans
        r1_x, r1_y = r1
        r2_x, r2_y = r2
        if n>=ans:
            return
        if r1 == [bs-1,bs-1] or r2==[bs-1, bs-1]:
            ans = min(ans, n)
            return
        for a, b in d:
            x1 = r1_x+a
            y1 = r1_y+b
            x2 = r2_x+a
            y2 = r2_y+b
            if 0<=x1<bs and 0<=y1<bs and 0<=x2<bs and 0<=y2<bs:
                if board[x1][y1] ==0 and board[x2][y2] ==0:
                    dfs([x1,y1],[x2,y2], n+1)
        if r1_x == r2_x: # 가로
            if 0<=r1_x-1 and board[r1_x-1][r1_y]==0 and board[r2_x-1][r2_y]==0: # 위쪽으로
                dfs([r1_x, r1_y], [r1_x-1, r1_y], n+1)
                dfs([r2_x, r2_y], [r2_x-1, r2_y], n+1)
            if r1_x+1<bs and board[r1_x+1][r1_y]==0 and board[r2_x+1][r2_y]==0: # 아래로
                dfs([r1_x, r1_y], [r1_x+1, r1_y], n+1)
                dfs([r2_x, r2_y], [r2_x+1, r2_y], n+1)
        if r1_y == r2_y: # 세로
            if 0<=r1_y-1 and board[r1_x][r1_y-1]==0 and board[r2_x][r2_y-1]==0: # 왼쪽으로
                dfs([r1_x, r1_y], [r1_x, r1_y-1], n+1)
                dfs([r2_x, r2_y], [r2_x, r2_y-1], n+1)
            if r1_y+1<bs and board[r1_x][r1_y+1]==0 and board[r2_x][r2_y+1]==0:
                dfs([r1_x, r1_y], [r1_x, r1_y+1], n+1)
                dfs([r2_x, r2_y], [r2_x, r2_y+1], n+1)
        
    dfs([0,0], [0,1], 0)
        
    
    return ans
'''