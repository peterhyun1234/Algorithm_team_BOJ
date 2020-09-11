from collections import deque
def solution(number, k):
    answer = ''
    n = len(number)
    if n==k:
        return '0'
    number = deque(number)
    stack = []
    cnt = 0
    stack.append(number[0])
    number.popleft()
    
    while cnt<=k and deque and number:
        now = number.popleft()
        while stack and cnt<k:
            if stack[-1]<now:
                stack.pop()
                cnt += 1
            else:
                break
        stack.append(now)
    if cnt!=k:
        stack = stack[:-(k-cnt)]
    answer = ''.join(stack)
            
    
    return answer