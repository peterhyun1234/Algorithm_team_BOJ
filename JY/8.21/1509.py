

s = input()
n = len(s)
dp = [[False]*(n+1) for _ in range(n+1)]
result = [float('inf')] * (n+1)
result[0] = 0


for i in range(1, n+1):
    dp[i][i] = True

for i in range(1, n):
    if s[i-1] == s[i]:
        dp[i][i+1] = True

for i in range(2, n):
    for j in range(1, n+1-i):
        if s[j-1] == s[j+i-1] and dp[j+1][i+j-1] == 1:
            dp[j][i+j] =True

for i in range(1, n+1):
    result[i] = min(result[i], result[i-1] + 1)
    for j in range(i+1, n+1):
        if dp[i][j]:
            result[j] = min(result[j], result[i-1] + 1)

print(result[n])





'''
for i in range(len_s):
    dp[i][i] = True


for i in range(len_s-1):
    if s[i] == s[i+1]:
        dp[i][i+1] = True

for i in range(len_s-2):
    for j in range(len_s-i-1):
        if s[j] == s[len_s-i-1] and dp[j+1][len_s-i-2]:
            dp[j][len_s-i-1] = True

print(dp)'''