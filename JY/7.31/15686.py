import sys
from itertools import combinations

input = sys.stdin.readline

N, M = map(int, input().split())

city_info = [input().split() for _ in range(N)]


house_li = []
chi_li = []
d = []
for i in range(N):
    for j in range(N):
        if city_info[i][j] == '1':
            house_li.append([i, j])
        elif city_info[i][j] == '2':
            chi_li.append([i, j])

chi_com = list(combinations(chi_li, M))

ans = 10000000
for chi_ in chi_com:
    all_d = 0
    for house in house_li:
        mi = 1000
        for chi in chi_:
            chi_d = abs(house[0]-chi[0]) + abs(house[1]-chi[1])
            mi = min(mi, chi_d)
        all_d += mi
    ans = min(ans, all_d)

print(ans)