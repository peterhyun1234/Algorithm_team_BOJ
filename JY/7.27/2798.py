import sys

input = sys.stdin.readline

N, M = map(int, input().split())

li = list(map(int, input().split()))

mi = 300000
for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1,N):
            a = li[i]+li[j]+li[k]
            if M-a>=0:
                mi = min(mi, M-a)
            
print(M-mi)