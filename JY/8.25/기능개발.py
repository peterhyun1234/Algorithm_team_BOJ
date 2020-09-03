def solution(progresses, speeds):
    ans = []
    n = len(progresses)
    li = []
    for i in range(n):
        p = progresses[i]
        s = speeds[i]
        p_r = 100-p
        if p_r%s==0:
            li.append(p_r//s)
        else:
            li.append(p_r//s+1)
    m = li[0]
    cnt = 1
    print('li:', li)
    for i in range(1, n):
        if m>=li[i]:
            cnt += 1
        else:
            ans.append(cnt)
            cnt = 1
            m = li[i]
    ans.append(cnt)
    
    return ans