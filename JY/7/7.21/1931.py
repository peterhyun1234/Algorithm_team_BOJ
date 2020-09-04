import sys

input = sys.stdin.readline

N = int(input())
li = []
t_li = [False]*(3000000)
count = 0

for _ in range(N):
    li.append(list(map(int, input().split())))
    
li.sort(key=lambda x: x[0])
li.sort(key=lambda x: x[1])

last = 0

for i in li:
    
    if i[0] >= last:
        count += 1
        last = i[1]

    
print(count) 