def solution(routes):
    ans = 0
    routes.sort(key=lambda x: x[1])
    routes.sort(key=lambda x: x[0])
    
    mi = routes[0][1]
    for start, end in routes:
        if start>mi:
            ans += 1
            mi = end
        elif end<mi:
            mi = end
        
    ans +=1
    
    return ans