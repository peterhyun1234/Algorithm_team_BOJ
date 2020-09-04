import sys

input= sys.stdin.readline

n = int(input())

dp = [None]*(n+1)

if n ==1 or n==2:
    print(n)

else: 
    dp[1], dp[2] = 1, 2
    for i in range(3,n+1):
        dp[i] = dp[i-1]%10007 + dp[i-2]%10007

    print(dp[n]%10007)

