import sys
n = int(input())

li = []
dp = [[None]*i for i in range(1, n+1)]

for _ in range(n):
    li.append(list(map(int, input().split())))
dp[0][0] = li[0][0]

if n==1:
    print(dp[0][0])
else:
    for i in range(1, n):
        for j in range(i+1):
            if j-1<0:
                left = 0
            else:
                left = dp[i-1][j-1]
            if j==i:
                right = 0
            else:
                right = dp[i-1][j]
            dp[i][j] = max(left, right) + li[i][j]

print(max(dp[n-1]))
    
    