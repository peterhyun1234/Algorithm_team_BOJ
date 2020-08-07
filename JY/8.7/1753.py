import sys
import heapq
input = sys.stdin.readline
INF = 10000000
V, E = map(int, input().split())
K = int(input())
li = [list(map(int, input().split())) for _ in range(E)]

graph = dict()
minw_li = [INF]*(V+1)

for fromV, toV, w in li:
    if fromV not in graph:
        graph[fromV] = []
    
    graph[fromV].append([w, toV])
s = set()
arr = []
heapq.heappush(arr, [0, K])
minw_li[K] = 0

while arr:
    fromw, fromV = heapq.heappop(arr)
    if fromV in graph and fromV not in s:
        s.add(fromV)
        for tow, toV in graph[fromV]:
            minw_li[toV] = min(minw_li[toV], minw_li[fromV]+tow)
            heapq.heappush(arr, [minw_li[toV], toV])

for i in range(1,V+1):
    if minw_li[i]==INF:
        print('INF')
    else:
        print(minw_li[i])


'''
for toV in range(V+1):
    minw_li[toV] = graph[K][toV]
minw_li[K] = 0    

while stack:
    fromV = stack.pop()

    for toV in range(V+1):
        if graph[fromV][toV] !=INF:
            stack.append(toV)
            minw_li[toV] = min(minw_li[toV], minw_li[fromV]+graph[fromV][toV])
        
for i in range(1, V+1):
    if minw_li[i] == INF:
        print('INF')
    else:
        print(minw_li[i])
'''
        

'''
3 2
3
1 3 10
2 1 4'''