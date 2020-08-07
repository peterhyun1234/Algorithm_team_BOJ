import sys
import heapq
input = sys.stdin.readline
INF = 1000000000
V = int(input())
E = int(input())
li = [list(map(int, input().split())) for _ in range(E)]
K, end = map(int, input().split())

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

print(minw_li[end])