def solution(li_p, li_c):
    ans = ''
    dic = {}
    for i in li_c:
        if i in dic:
            dic[i] += 1
        else:
            dic[i] = 1
    
    
    for i in li_p:
        if i not in dic:
            return i
        else:
            dic[i] -= 1
            if dic[i]<0:
                return i