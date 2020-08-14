import sys

input = sys.stdin.readline

N, C = map(int, input().split())

house = [int(input()) for _ in range(N)]

house = sorted(house)

start = 1
end = house[-1]-house[0]

while start<=end:
    count = 1
    mid = (end+start)//2
    cur_house = house[0]
    for i in range(1, N):
        if house[i]-cur_house >= mid:
            count += 1
            cur_house = house[i]

    if count>=C:
        ans = mid
        start = mid+1
    else:
        end = mid-1

print(ans)    
    
    