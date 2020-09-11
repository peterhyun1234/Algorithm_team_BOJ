def solution(n, costs):
    ans = 0
    u_arr = list(range(n))

    def union(x, y):
        x_pa, y_pa = u_arr[x], u_arr[y]
        while u_arr[x_pa]!=x_pa:
            x_pa = u_arr[x_pa]
        while u_arr[y_pa]!=y_pa:
            y_pa = u_arr[y_pa]
        if x_pa==y_pa:
            return False
        else:
            u_arr[y_pa] = x_pa
            return True
    costs.sort(key=lambda x: x[2])
    for s, e, w in costs:
        if union(s,e):
            ans+=w
        
        
    return ans