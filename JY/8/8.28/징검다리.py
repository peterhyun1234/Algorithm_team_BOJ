def solution(distance, rocks, n):
    ans = 0
    rocks.sort()
    rn = len(rocks)
    start = 0
    end = distance
    while start<end:
        mid = (start+end)//2
        cnt = 0
        tmp = 0
        flag = False
        for i in range(rn):
            if rocks[i]-tmp<mid:
                if cnt<n:
                    cnt += 1
                    continue
                else:
                    flag = True
                    break
            else:
                tmp = rocks[i]
        print(mid)   
        if flag:
            end = mid
        else:
            start = mid +1
    ans = end-1
    return ans