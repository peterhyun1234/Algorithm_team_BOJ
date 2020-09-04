from collections import Counter
from itertools import product

s1, s2, s3 = map(int, input().split())
li = product(range(1, s1+1), range(1, s2+1), range(1, s3+1))
ss = []
for i in li:
    ss.append(sum(i))

c = Counter(ss)
print(c.most_common(1)[0][0])
