import sys

input = sys.stdin.readline

# 1. 어떤 전자제품을 사용할지 확인한다.
# 2. 1에서 비어있으면 꽂는다.
# 3. 1에서 이미 꽂혀있으면 넘어간다.
# 4. 1에서 이미 가득차있고 하나를 뽑아야한다면,
#    기존에 꽂혀있는 것 중에 가장 나중에 사용되는 것을 찾아서 뽑고 꽂는다.(이때 카운트를 센다.)
# 5. 앞을 반복한다.

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
            


        
