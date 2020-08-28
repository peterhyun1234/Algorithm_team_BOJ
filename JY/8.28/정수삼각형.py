def solution(triangle):
    ans = 0
    n = len(triangle)
    dp = [[0]*i for i in range(1, n+1)]
    
    dp[0][0] = triangle[0][0]
    for i in range(1, n):
        for j in range(i+1):
            if j-1>=0 and j<i:
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
            elif j==0:
                dp[i][j] = dp[i-1][j] + triangle[i][j]
            elif j==i:
                dp[i][j] = dp[i-1][j-1] + triangle[i][j]
    ans = max(dp[n-1])
    return ans