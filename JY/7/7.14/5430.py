import sys
from collections import deque
input = sys.stdin.readline

T = int(input())

for i in range(T):
    e = False               #error
    r = False               #reverse
    p = input()             #function list
    n = int(input())                                    
    arr = input()
    if len(arr)==3:
        arr = []
    else:
        arr = arr[1:-2].split(',')
    arr = deque(arr)
    
    if p.count('D')>len(arr):
            e = True
    else:
        for i in p:
            if i=='R':
                if r == True:
                    r = False
                else:
                    r = True

            if i=='D':
                if r == True:
                    arr.pop()
                else:
                    arr.popleft()
    
    arr =list(arr)

    if e == True:
        print('error')

    else:
        if r == True:
            arr.reverse()
        a = ','.join(arr)
        print('['+ a + ']')