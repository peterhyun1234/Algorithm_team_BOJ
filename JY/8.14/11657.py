import sys

input = sys.stdin.readline
N, M = map(int, input().split())
edges = dict()

for _ in range(M):
    a, b, c = map(int, input().split())
    if a not in edges:
        edges[a] = []
    edges[a].append([b, c])


dist = [float('inf')]*(N+1)

dist[1] = 0
cycle = False
for count in range(1, N+1):
    for i in edges:
        for end, w in edges[i]:
            if dist[i]+w< dist[end]:
                dist[end] = dist[i]+w
                # dist[end] = min(dist[i]+w, dist[end])
                if count==N:
                    print(-1)
                    exit()
                    break
        

for i in dist[2:]:
    if i==float('inf'):
        print(-1)
    else:
        print(i)
