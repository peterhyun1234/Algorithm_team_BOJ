import sys

input = sys.stdin.readline

N = int(input())

#li = list(map(int, input().split()))
li = input().split()
for i in li:
    h = int(i, 16)
    if h & 64 != 0:
        print('-',end='')
    else:
        print('.',end='')
print()