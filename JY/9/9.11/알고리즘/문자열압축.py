def solution(s):
    ans = 11110
    n = len(s)
    if n==1:
        return 1
    for i in range(1, n//2+1):
        temp_ans = ''
        pre = ''
        count = 1
        for k in range(n//i+1):
            temp = s[k*i:k*i+i]
            #print(temp)
        
            if pre!=temp:
                if count!=1:
                    temp_ans += str(count)+pre
                    count = 1
                else:
                    temp_ans += pre
                pre=temp    
            else:
                count+=1
        if count!=1:
            temp_ans+=str(count)
        temp_ans+=temp
        ans = min(len(temp_ans), ans)
    return ans