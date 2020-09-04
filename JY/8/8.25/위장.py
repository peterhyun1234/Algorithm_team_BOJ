from collections import defaultdict
from itertools import combinations

def solution(clothes):
    ans = 0
    dic = defaultdict(int)
    for c_name, c_type in clothes:
        dic[c_type] += 1
    n = len(dic)
    if n==30:
        return 2**30-1
    for i in range(1, n+1):
        cnt = 0
        for j in combinations(dic.keys(), i):
            s = 1
            for k in j:
                s *= dic[k]
            cnt += s
        ans += cnt
    
    return ans