def solution(n, lost, reserve):
    ans = 0
    dic = {i:1 for i in range(1,n+1)}
    for i in lost:
        dic[i] -= 1
    for i in reserve:
        dic[i] += 1
    li = [True] + [False]*n
    for i in dic:
        if dic[i]!=0:
            print("지옷있음",i)
            li[i] = True
            dic[i] -= 1
            ans +=1
    
    for i in range(1, n+1):
        if li[i] == False:
            for j in dic:
                if abs(j-i)<=1:
                    if dic[j]>0:
                        print('빌림', i, j,dic[j])
                        dic[j] -= 1
                        ans += 1
                        break
        
                
    return ans