import sys

input = sys.stdin.readline

N = int(input())
li = [int(input()) for _ in range(N)]

stack = []


for i in li:
    if i < stack[-1]:
        temp = stack[-1]
        while stack[-1]<temp:
            stack.pop()
            lastlen += 1
        ma = max(lastlen*temp, ma)
    if i>=stack[-1]:
        lastlen = 0
    stack.append(i)
    stack[-1]