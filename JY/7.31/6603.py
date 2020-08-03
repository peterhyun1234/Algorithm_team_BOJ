'''
import sys

input = sys.stdin.readline

while True:
    k, *li = map(int, input().split())
    if not li:
        break
    for a in range(k-5):
        for b in range(a+1,k-4):
            for c in range(b+1,k-3):
                for d in range(c+1, k-2):
                    for e in range(d+1, k-1):
                        for f in range(e+1, k):
                            print(li[a], end=' ')
                            print(li[b], end=' ')
                            print(li[c], end=' ')
                            print(li[d], end=' ')
                            print(li[e], end=' ')
                            print(li[f])

    print()

'''

import sys
from itertools import combinations
input = sys.stdin.readline

while True:
    k, *li = list(map(int, input().split()))
    if not li:
        break
    li = combinations(li, 6)
    for i in li:
        for j in i:
            print(j, end=' ')
        print()
    print()