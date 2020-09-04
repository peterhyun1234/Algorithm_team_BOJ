import sys

input = sys.stdin.readline

li = []
z_li = []
stack = []
for _ in range(9):
    li.append(list(map(int, input().split())))

for i in range(9):
    for j in range(9):
        if li [i][j] == 0:
            z_li.append([i,j])

def promising(li, x, y, num, visit):
    temp_li = li[:]
    for i, j, num in visit:
        temp_li[i][j] = num

    for j in range(9):
        if num == li[x][j]:
            return False
    for i in range(9):
        if num == li[i][y]:
            return False
    for i in range((x//3)*3, (y//3)*3+3):
        for j in range((x//3)*3, (y//3)*3+3):
            if li[i][j]==num:
                return False
    return True


for num in range(1, 10):
    if promising(li, *z_li.pop(), num, []):
        stack.append([*z_li.pop(), num])


visit = []

while z_li:
    node = stack.pop()
    visit.append(node)
    temp = z_li.pop()
    for num in range(1, 10):
        if promising(li, *temp, num, visit):
            stack.append([*temp, num])
    
    
    