from collections import deque

def solution(begin, target, words):
    if target not in words:
        return 0
    ans = 0
    def comp(a, b):
        if len(a)!=len(b):
            return False
        cnt = 0
        for i in range(len(a)):
            if a[i]!=b[i]:
                cnt+=1
            if cnt>=2:
                return False
        return True
    
    queue = deque()
    queue.append([begin, 0])
    
    while queue:
        w, cnt = queue.popleft()
        if w==target:
            return cnt
        for i in words:
            if comp(w,i):
                queue.append([i, cnt+1])

            
    
    return ans