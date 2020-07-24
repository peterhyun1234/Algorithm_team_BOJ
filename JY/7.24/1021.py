from collections import deque

N, M = map(int, input().split())
li = map(int, input().split())
q = deque(range(1,N+1))
left = 1
right = N

ans = 0
for i in li:
    if q[0] == i:
        q.popleft()
    else:
        templ = deque(list(q)[:])
        tempr = deque(list(q)[:])
        countl = 0
        countr = 0
        while templ[0] != i:
            templ.rotate(-1)
            countl += 1
        while tempr[0] != i:
            tempr.rotate(1)
            countr += 1
        ans += min(countl,countr)
        q = templ
        q.popleft()

print(ans)
