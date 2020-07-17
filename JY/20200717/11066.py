import sys

input = sys.stdin.readline

T = int(input())

def func(li):
    li.sort()
        if len(li)%2 != 0:
            last_li.append(li.pop())
        for i in range(len(li)//2):
            temp_li.append(li[i*2]+li[i*2+1])
        li = temp_li


for _ in range(T):
    count = 0
    k = int(input())
    li = list(map(int, input().split()))
    
    temp_li = []
    while li:
        last_li = []
        li.sort()
        while li:
            if len(li)%2 != 0:
                last_li.append(li.pop())
            for i in range(len(li)//2):
                a = li[i*2]+li[i*2+1]
                temp_li.append(a)
                count += a
            li = temp_li
            temp_li.clear()
        li = last_li
    print(count)
    





    li.sort()
    for i in li:
        count += count + i
    print(count)
