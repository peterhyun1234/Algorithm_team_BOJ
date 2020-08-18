import sys

N = int(input())
end = 0
start = float('inf')
li = []
for _ in range(N):
    a, c, b = map(int, input().split())
    start = min(start, a)
    end = max(end, c)
    li.append([a, c, b])


def func(n):
    count = 0
    for a, c, b in li:
        if a<=n:
            i = 0
            while a+i*b<=c and a+i*b<=n:
                count += 1
                i += 1
    return count

def cnt(num):
    count = 0
    for a, c, b in li:
        if a<=num:
            i = 0
            while a+i*b<=c and a+i*b<=num:
                if a+i*b==num:
                    count += 1
                i += 1
    return count

while start<end:
    mid = (start+end)//2
    if func(mid)%2==1:
        end = mid
    else:
        start = mid+1
if func(end)%2==1:
    print(end, end=' ')
    print(cnt(end))
else:
    print('NOTHING')
    
