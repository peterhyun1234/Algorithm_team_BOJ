import sys
import heapq
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    M = int(input())
    li = []
    k = 0
    for _ in range(M//10+1):
        li.extend(list(map(int, input().split())))
    arr = []
    print(M//2+1)
    for i in range(1, M+1):
        
        heapq.heappush(arr, li[i-1])
        temp_li = []
        if i%2 == 1:
            for _ in range(i//2):
                temp_li.append(heapq.heappop(arr))
            print(arr[0], end=' ')
            if k//10 != (k+1)//10:
                print()
            k += 1

            for _ in range(i//2):
                heapq.heappush(arr, temp_li.pop())
            
    print()
    