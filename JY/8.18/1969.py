import sys
input = sys.stdin.readline



N, M = map(int, input().split())

li = [input().strip() for _ in range(N)]
ans = ''
count = 0

for k in range(M):
    acgt = {'A': 0, 'C':0, 'G':0, 'T':0}
    for i in range(N):
        acgt[li[i][k]] += 1
    temp = 0
    pre =0
    for i in acgt.keys():
        if acgt[i]>pre:
           rec = [i, acgt[i]]
           pre = acgt[i]
    ans += rec[0]
    count += N-rec[1]





print(ans)
print(count)



