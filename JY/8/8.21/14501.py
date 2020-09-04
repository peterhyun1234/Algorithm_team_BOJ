import sys
input = sys.stdin.readline

N = int(input())
li = [[None]]
li.extend([list(map(int, input().split())) for _ in range(N)])


dp = [0]*(N+10)

for i in range(1, N+1):
    end = li[i][0] + i - 1
    v = li[i][1]

    dp[end] = max(dp[end], dp[i-1]+v)
    for j in range(end+1, N+1):
        dp[j] = max(dp[end], dp[j])


print(dp[N])