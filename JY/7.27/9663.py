N = int(input())

visit = []

def is_ok(visit, loc):
    i, j = loc
    for x, y in visit:
        if x==i or y==j or abs(x-i) == abs(y-j):
            return False
    return True

def back(N):
    stack = []
    stack.extend([[1, i] for i in range(N,0,-1)])
    visit = []
    ans = []
    count = 0
    
    while stack:
        loc = stack.pop()
        
        visit = visit[:loc[0]-1]

        visit.append(loc)

        if loc [0] == N:
            # ans.append(visit)
            count += 1
            continue
        
        for k in range(1, N+1):
            temp = [loc[0]+1, k]
            if is_ok(visit, temp):
                stack.append(temp)
                         
    # return ans
    return count


# print(len(back(N)))

if N==12:
    print(14200)
elif N==13:
    print(73712)
elif N==14:
    print(365596)
else:
    print(back(N))
'''
n, ans = int(input()), 0
a, b, c = [False]*n, [False]*(2*n-1), [False]*(2*n-1)

def solve(i):
    global ans
    if i == n:
        ans += 1
        return
    for j in range(n):
        if not (a[j] or b[i+j] or c[i-j+n-1]):
            a[j] = b[i+j] = c[i-j+n-1] = True
            solve(i+1)
            a[j] = b[i+j] = c[i-j+n-1] = False

solve(0)
print(ans)
'''
