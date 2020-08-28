def solution(numbers, target):
    ans = 0
    n = len(numbers)
    stack = []
    
    stack.append([1])
    stack.append([2])
    
    while stack:
        node = stack.pop()
        if len(node) == n:
            s = 0
            for i in range(n):
                if node[i]==1:
                    s += numbers[i]
                if node[i]==2:
                    s -= numbers[i]
            if s == target:
                ans += 1
            continue
        stack.append(node+[1])
        stack.append(node+[2])
    return ans