import sys

input = sys.stdin.readline

N, M = map(int, input().split())

li = [list(map(int, input().split())) for _ in range(M)]

stack = []
graph = {}
g_count = {i:0 for i in range(1, N+1)}
ans = []
for a, b in li:
    if a not in graph:
        graph[a] = []

    graph[a].append(b)
    g_count[b] += 1

for i in g_count:
    if g_count[i]==0:
        stack.append(i)

while stack:
    zero_in = stack.pop()
    if zero_in in graph:
        for i in graph[zero_in]:
            g_count[i] -= 1
            if g_count[i] == 0:
                stack.append(i)
        del graph[zero_in]
    ans.append(zero_in)

for i in ans:
    print(i, end=' ')