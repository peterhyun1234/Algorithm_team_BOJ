import sys

input = sys.stdin.readline
n = int(input())
li = [0]
li.extend([int(input()) for _ in range(n)])
li.extend([0, 0])
dp = [None]*(n+2)
dp[0], dp[1], dp[2] = 0, li[1], li[1]+li[2]
def func(k):
    if dp[k] != None:
        return dp[k]
    else:
        dp[k] = max(func(k-3)+li[k-1], func(k-2)) + li[k]
        return dp[k]

print(func(n))
