import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    M, N, K = map(int, input().split())
    li = [list(map(int, input().split())) for _ in range(K)]
    
    stack = []
    visit = []
    count = 0

    while len(visit)<K:
        for i in li:
            if i not in visit:
                stack.append(i)
                visit.append(i)
                break
        
        while stack:
            node = stack.pop()

            if [node[0]+1, node[1]] not in visit and [node[0]+1, node[1]] in li:
                stack.append([node[0]+1, node[1]])
                visit.append([node[0]+1, node[1]])
            if [node[0]-1, node[1]] not in visit and [node[0]-1, node[1]] in li:
                stack.append([node[0]-1, node[1]])
                visit.append([node[0]-1, node[1]])    
            if [node[0], node[1]-1] not in visit and [node[0], node[1]-1] in li:
                stack.append([node[0], node[1]-1])
                visit.append([node[0], node[1]-1])
            if [node[0], node[1]+1] not in visit and [node[0], node[1]+1] in li:
                stack.append([node[0], node[1]+1])
                visit.append([node[0], node[1]+1])
        count += 1
    
    print(count)
