import sys
import heapq

input = sys.stdin.readline

n, m = list(map(int, input().split()))

delivery_graph = dict()
ans_li = [[0]*n for _ in range(n)]
for _ in range(m):
    x, y, w  = map(int, input().split())
    if x not in delivery_graph:
        delivery_graph[x] = []
    if y not in delivery_graph:
        delivery_graph[y] = []
    delivery_graph[x].append([y, w])
    delivery_graph[y].append([x, w])

def func(fromV):
    visit = [False]*(n+1)
    val_map = [1000000000]*(n+1)
    heaparr = []
    heapq.heappush(heaparr, [0, fromV])
    ret_li = [0]*(n+1)
    while heaparr:
        val, x = heapq.heappop(heaparr)
        if not visit[x]:
            visit[x] = True
            val_map[x] = max(val_map[x], val)
            for i in delivery_graph[x]:
                y, val = i
                if not visit[y]:
                    if val_map[y] >= val_map[x]+val:
                        heapq.heappush(heaparr, [val, y])
                        ret_li[y]=x
    
    return ret_li
for i in range(1, n+1):
    print(func(i))
    


    
    
