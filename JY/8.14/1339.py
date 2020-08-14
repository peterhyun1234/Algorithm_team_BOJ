import sys

input = sys.stdin.readline

N = int(input())

alphabet_li = [input().strip() for _ in range(N)]

num_dic = dict()
for i in alphabet_li:
    l = len(i)-1
    for j in i:
        if j not in num_dic:
            num_dic[j] = 0
        num_dic[j] += 10**l
        l -= 1

num_li = sorted(list(num_dic.values()), reverse=True)
k = 9
s = 0
for i in num_li:
    s += i*k
    k -= 1
print(s)