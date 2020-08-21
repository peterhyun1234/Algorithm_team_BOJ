import sys
input = sys.stdin.readline
N, M, K = map(int, input().split())

A = [[0]*(N+1)]
for _ in range(N):
    A.append(list(map(int, [0]+input().split())))

adjacent = [[-1,-1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]

nour_map = [[5]*(N+1) for _ in range(N+1)]

trees = [list(map(int, input().split())) for _ in range(M)]

tree_map = [[0]*(N+1) for _ in range(N+1)]

for x, y, z in start_trees:
    tree_map[x][y] = z

    

def spring():
    for i in range(len(trees)):
        x, y, z = trees[i]
        if nour_map[x][y] == 0