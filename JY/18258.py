import sys
from collections import deque
input = sys.stdin.readline
N = int(input())
li = []

def push(queue, n):
    queue.append(n)

def front(queue):
    if len(queue)==0:
        print(-1)
    else:
        print(queue[0])

def back(queue):
    if len(queue)==0:
        print(-1)
    else:
        print(queue[-1])
def pop(queue):
    if len(queue)==0:
        print(-1)
    else:
        print(queue.popleft())

def size(queue):
    print(len(queue))

def empty(queue):
    if len(queue)==0:
        print(1)
    else:
        print(0)


q= deque()
for _ in range(N):
    li = input().split()
    if li[0] == 'push':
        push(q, int(li[1]))
    if li[0] == 'front':
        front(q)
    if li[0] == 'pop':
        pop(q)
    if li[0] == 'empty':
        empty(q)
    if li[0] == 'back':
        back(q)
    if li[0] == 'size':
        size(q)
    li.clear()
