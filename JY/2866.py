import sys
import collections

input = sys.stdin.readline

R, C = map(int, input().split())

li = [input() for _ in range(R)]
li = collections.deque(li)

ans_li = collections.deque()
dic = collections.Counter()
count = -1
wrong = False
for i in range(len(li[0])): # column parsing
        s = ''
        for j in range(len(li)):
            s += li[j][i]
        ans_li.append(s)

while True:
    
    if len(ans_li) == 0:
        break
    dic = collections.Counter(ans_li) # words num
    
    if dic.most_common(1)[0][1] > 1:
        wrong = True
        break
    if wrong == True:
        break

    count += 1
    for i in range(C):
        ans_li[i] = ans_li[i][1:]
    

print(count)
    
