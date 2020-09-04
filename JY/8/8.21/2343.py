import sys
input = sys.stdin.readline

N, M = map(int, input().split())
li = list(map(int, input().split()))
s = sum(li)
start = 1
end = 10000*M

ans = 0

while start<end:
    mid = (start+end)//2
    s = 0
    count = 0
    sobig = False
    for i in li:
        if i>mid:
            sobig =True
            break
        if s+i <= mid:
            s += i
        else:
            s = i
            count += 1
    count += 1
    if sobig:
        start = mid +1
    elif M>=count:
        end = mid
    else:
        start = mid + 1
print(end)

"""
def lower_bound(li,target):
    start = 0
    end = len(li)-1
    while start<end:
        mid = (start+end)//2
        if li[mid] >=target:
            end = mid
        else:
            start = mid +1
    return end

ans = 0
bluray_len = 0
for i in range(N):
    bluray_len += li[i]
    if bluray_len>=limit:
        if abs(limit-bluray_len)>abs(limit-((bluray_len-li[i]))):
            ans = max(ans, bluray_len-li[i])
            bluray_len = li[i]
        else:
            ans = max(ans, bluray_len)
            bluray_len = 0
print(ans)

'''
4 2
1 1 1 1
'''"""