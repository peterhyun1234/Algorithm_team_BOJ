from collections import deque

queue = deque()
queue.extend([1,2,3])
queue.rotate(-1)
print(list(queue))


def solution(priorities, location):
    ans = 0
    tmp = priorities[:]
    n = len(priorities)
    tmp.sort()
    pri_li = [(i, priorities[i]) for i in range(n)]
    pri_li = deque(pri_li)
    while True:
        m = tmp.pop()
        if m!=pri_li[0][1]:
            while m !=pri_li[0][1]:
                pri_li.rotate(-1)
        popone = pri_li.popleft()
        ans += 1
        if location==popone[0]:
            break
            
    return ans