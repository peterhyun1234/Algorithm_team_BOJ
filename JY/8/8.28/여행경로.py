from collections import defaultdict
def solution(tickets):
    ans = []
    graph = defaultdict(list)
    for i, j in tickets:
        graph[i].append(j)
    for i in graph:
        graph[i].sort(reverse=True)
   
    stack = []
    stack.append('ICN')
    while stack:
        node = stack[-1]
        if not graph[node]:
            ans.append(stack.pop())
        else:
            stack.append(graph[node].pop())
    ans.reverse() 
    print(ans)
    return ans