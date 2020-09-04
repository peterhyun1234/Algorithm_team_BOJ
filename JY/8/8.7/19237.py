import sys
input = sys.stdin.readline

N, M, k = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(N)]
sh_d = [[]]
sh_d.extend(list(map(int, input().split())))
prs = [[]]

for _ in range(M):
    prs.append([list(map(int, input().split())) for _ in range(4)]) 

sharks = [[] for _ in range(M+1)]
for i in range(N):
    for j in range(N):
        for m in range(1, M+1):
            if board[i][j] == m:
                sharks[m] = [i, j, sh_d[m]]

# sharks[i] = x, y, d 

directions = [[0, 0], [-1, 0], [1, 0], [0, -1], [0, 1]]

sec = 0
smells = dict()
for i in range(1, M+1):
    x, y, d = sharks[i]
    smells[f"{x} {y}"] = [i, k]

sharks_alive = [True]*(M+1)
def shark_move(sh_num):
    can_move = False
    x, y, d = sharks[sh_num]
    pr = prs[sh_num][d-1]
    for p in pr:
        i, j = directions[p]
        a = x+i # a = 이동할 위치
        b = y+j # b = 이동할 위치
        if 0<=a<N and 0<=b<N:
            if f"{a} {b}" not in smells:
                sharks[sh_num] = [a, b, p]
                can_move = True
                break
    if not can_move:
        for p in pr:
            i, j = directions[p]
            a = x+i
            b = y+j
            if 0<=a<N and 0<=b<N:
                if f"{a} {b}" in smells and smells[f"{a} {b}"][0]==sh_num:
                    sharks[sh_num] = [a, b, p]
                    break

def shark_check(): # 죽은 상어 체크 냄새 체크
    for i in range(1, M+1):
        for j in range(i+1,M+1):
            if sharks_alive[i] and sharks_alive[j]:
                if sharks[i][:-1] == sharks[j][:-1]:
                    sharks_alive[j] = False
    for i in range(1, M+1):
        if sharks_alive[i]:
            x, y, d = sharks[i]
            smells[f"{x} {y}"] = [i, k+1]


while sec<1001:
    remove_li = []
    for i in range(1, M+1):
        if sharks_alive[i]:
            shark_move(i)
    shark_check()
    for i in smells.keys():
        smells[i][1] -= 1
        if smells[i][1] == 0:
            # del smells[i]
            remove_li.append(i)
    for i in remove_li:
        del smells[i]
    sec+=1

    if sharks_alive.count(True)==2:
        break

if sec==1001:
    print(-1)
else:
    print(sec)
