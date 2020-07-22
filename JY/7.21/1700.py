import sys

input = sys.stdin.readline

N, K = map(int, input().split())

li = list(map(int, input().split()))

mul_li = set()

count = 0
mul_count = 0
a = 0
b = 0
for i in range(K):

    if len(mul_li)<N:
        mul_li.add(li[i])
        continue
    elif li[i] in mul_li:
        continue
    else:
        a = 0
        b = 0
        for j in mul_li:
            try:
                k = li[i:].index(j)
                if k>a:
                    a = k
                    b = j
            
            except:
                a = -1
                b = j
                break
        mul_li.remove(b)
        mul_li.add(li[i])
        count +=1

print(count)
            


        
