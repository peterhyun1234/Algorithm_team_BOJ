from itertools import permutations
check = [False]*(10**8)

def solution(numbers):
    ans = 0
    n = len(numbers)
    numbers = list(numbers)
    num_li = []
    for i in range(1, n+1):
        for j in permutations(numbers, i):
            tmp = ''.join(j)
            tmp = int(tmp)
            is_prime = True
            if not check[tmp]:
                check[tmp] = True
                for k in range(2, int(tmp**1/2)+1):
                    if tmp%k==0:
                        is_prime = False
                        break
                if tmp!=0 and tmp!= 1 and is_prime:
                    ans += 1
                    num_li.append(tmp)
    print(num_li)
                    
    
    
    return ans