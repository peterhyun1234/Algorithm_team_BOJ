import heapq

def solution(scoville, K):
    ans = 0
    arr = []
    n = len(scoville)
    can_make =False
    all_btk = True
    for i in scoville:
        heapq.heappush(arr, i)
        
    while len(arr)>1 and arr[0]<K:
        tmp1 = heapq.heappop(arr)
        tmp2 = heapq.heappop(arr)
        newf = tmp1+tmp2*2
        heapq.heappush(arr, newf)
        ans += 1
        
    if arr[0]<K:
        ans = -1
        
    return ans