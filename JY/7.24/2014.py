import heapq

K, N = map(int, input().split())
li = list(map(int, input().split()))
arr = []
count = 1
li2 = []

ans = li[0]
is_break = False
for i in li:
    heapq.heappush(arr, i)

a = 0

'''
while count <= 10*N:
    a = heapq.heappop(arr)
    li2.append(a)
    for i in li2:
        heapq.heappush(arr, i*a)
    count += 1'''

while count <= N:
    a = heapq.heappop(arr)
    
    for i in li:
        heapq.heappush(arr, i*a)

        if a % i == 0:
            break
    count += 1
        

print(a)
