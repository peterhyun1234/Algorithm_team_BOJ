from copy import deepcopy
ans = 1000
def solution(t, weak, dist):
    nw = len(weak)
    nd = len(dist)
    dist.reverse()
    def dfs(i, notvisit, n):
        global ans
        if n>=ans:
            return
        if not notvisit:
            ans = min(ans, n)
        if i==nd:
            return
        
        d = dist[i]
        for j in notvisit:
            temp = set(notvisit)
            '''
            for k in notvisit:
                if j+d>=t:
                    if j<=k or k<=(j+d)%t:
                        temp.remove(k)
                else:
                    if j<=k<=j+d:
                        temp.remove(k)
            '''                
                      
            for k in range(j, j+d+1):
                if k>=t:
                    k=k%t
                if k in temp:
                    temp.remove(k)
            
            dfs(i+1, temp, n+1)
    dfs(0, set(weak), 0)
    if ans==1000:
        return -1   
        
        
    return ans