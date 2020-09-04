
N = int(input())

dp1 = [[None]*10 for _ in range(101)]
dic1 = {i:False for i in range(10)}

def func(dp, N, num, dic):
    
    if dp[N][num]:
        return dp[N][num]
    if N==1:
        dp[N][num] = 1
        dic[num] = True
        for i in range(10):
            if dic[i] == False:
                dp[N][num] = 0
                break
        return dp[N][num]
    if num==0:

        dic[num] =True
        dp[N][num] = func(dp, N-1, num+1, dic)
        
        return dp[N][num]

    if num==9:
        dic[num] = True
        dp[N][num] = func(dp, N-1, num-1, dic)
        
        return dp[N][num]

    dic[num] = True
    dp[N][num] = func(dp, N-1, num-1, dic) + func(dp, N-1, num+1, dic)
    
    return dp[N][num]


s = 0
for i in range(1, 10):
    s += func(dp1, N, i, dic1)
print(s%1000000000)





'''
N = int(input())
li = [[None]*10 for _ in range(101)]
def func(N, num):
    if li[N][num]:
        return li[N][num]
    if N==1:
        li[N][num] = 1
        return li[N][num]
    if num==0:
        li[N][num] = func(N-1, num+1)
        return li[N][num]
    if num==9:
        li[N][num] = func(N-1, num-1)
        return li[N][num]
    li[N][num] = func(N-1, num-1) + func(N-1, num+1)
    return li[N][num]
    

s = 0
for i in range(1, 10):
    s += func(N, i)
print(s%1000000000)
'''