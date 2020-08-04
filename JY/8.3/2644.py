import sys
input = sys.stdin.readline

n = int(input())
start, finish = map(int, input().split())
m = int(input())

li = [list(map(int, input().split())) for _ in range(m)]

li_fa = [[] for _ in range(n+1)]

flag = False

for pa, ch in li:
    li_fa[pa].append(ch)
    li_fa[ch].append(pa)


def dfs(graph, start):
    stack = []
    visit = []
    stack.append([start, 0])
    
    while stack:
        node, count = stack.pop()
        if node == finish:
            print(count)
            return False
        if node not in visit:
            stack.extend([[i, count+1] for i in li_fa[node]])
            visit.append(node)
    return True

if dfs(li_fa,start):
    print(-1)
