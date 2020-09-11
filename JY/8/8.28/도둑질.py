def solution(money):
    dp1 = [0] * len(money)
    dp1[0] = money[0]
    dp1[1] = max(money[0], money[1])

    for i in range(2, len(money)-1): # 첫 집을 무조건 터는 경우
        dp1[i] = max(dp1[i-1], money[i]+dp1[i-2])

    dp2 = [0] * len(money)
    dp2[0] = 0
    dp2[1] = money[1]

    for i in range(2, len(money)): # 마지막 집을 무조건 터는 경우
        dp2[i] = max(dp2[i-1], money[i]+dp2[i-2])

    return max(max(dp1), max(dp2)) # 두 경우 중 최대

import sys
sys.setrecursionlimit(200000000)

def solution(money):
    ans = 0
    n = len(money)
    
    dp1 = [None]*n
    dp1[0], dp1[1], dp1[2] = money[0], 0, money[2]+money[0]
    def func1(k):
        if dp1[k]!=None:
            return dp1[k]
        dp1[k] = max(func1(k-1), func1(k-2)+money[k])
        return dp1[k]
    func1(n-1)
    
    dp2 = [None]*n
    dp2[0], dp2[1], dp2[2] = 0, money[1], max(money[1],money[2])
    def func2(k):
        if dp2[k] != None:
            return dp2[k]
        dp2[k] = max(func2(k-1), func2(k-2)+money[k])
        return dp2[k]
    func2(n-2)
    
    dp2[-1] =0
    #print(dp1, dp2)

    
    ans = max(*dp1[-2:],*dp2[-3:])
    
    return ans