import sys

C = int(input())

for _ in range(C):
    ans_li = [[0]*11 for _ in range(11)]
    li_tf = [False]*11
    li = [map(int, input().split()) for _ in range(11)]



def func(li):
    for i in range(11):
        for j in range(11):
            if li[i][j] == 0:
                continue
            else:
                