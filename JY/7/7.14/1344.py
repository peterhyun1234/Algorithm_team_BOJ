import sys

input = sys.stdin.readline

pa = int(input())/100
qa = 1-pa
resulta = 0

pb = int(input())/100
qb = 1-pb
resultb = 0

ans = 0
li = [2,3,5,7,11,13,17]

def nCr(n, r):
    ret = 1
    for i in range(n-r+1, n+1):
        ret *= i
    for i in range(1,r+1):
        ret /= i
    return ret

for i in li:
    resulta += (pa**i)*(qa**(18-i))*nCr(18, i)
    resultb += (pb**i)*(qb**(18-i))*nCr(18, i)


ans = 1-(1-resulta)*(1-resultb)

print(ans)
