import sys

input = sys.stdin.readline

N = int(input())

li = [input().strip() for _ in range(N)]
def key(s):
    ret = 0
    for i in s:
        try:
            ret += int(i)
        except:
            continue
    return ret
li.sort()
li.sort(key=key)
li.sort(key=lambda x: len(x))

for i in li:
    print(i)
