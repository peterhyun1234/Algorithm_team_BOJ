def solution(n, times):
    ans = 0
    m = min(times)
    start = 0
    end = m*n
    
    while start<end:
        mid = (start+end)//2
        cnt = 0
        for t in times:
            cnt += mid//t
        if cnt>=n:
            end = mid
        else:
            start= mid+1
        
    ans = end
    return ans