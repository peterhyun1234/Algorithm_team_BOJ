N = int(input())
arr = list(map(int, input().split()))
dp_up = [1]*N
dp_down = [1]*N
dp = [0]*N
arr_down = list(reversed(arr))
for i in range(N):
    for j in range(i):
        if arr[j]<arr[i]:
            dp_up[i] = max(dp_up[j]+1, dp_up[i])
        if arr[N-j-1]<arr[N-i-1]:
            dp_down[N-i-1] = max(dp_down[N-j-1]+1, dp_down[N-i-1])

for i in range(N):
    dp[i] = dp_up[i]+dp_down[i]
print(max(dp)-1)
