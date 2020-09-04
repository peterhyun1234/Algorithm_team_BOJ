
def solution(name):
    ans = 0
    n = len(name)
    target = ''
    name = list(name)
    loc = 0
    def func(li, loc):
        tar_r = (loc+1)%n
        tar_l = (loc-1)%n
        cnt_r = 1
        cnt_l = 1
        while li[tar_r]=='A':
            tar_r += 1
            tar_r = tar_r%n
            cnt_r += 1
        while li[tar_l]=='A':
            tar_l -= 1
            tar_l = tar_l%n
            cnt_l += 1
        if cnt_r<cnt_l:
            return [tar_r,cnt_r]
        else:
            return [tar_l,cnt_l]
        
    all_a = ['A']*n    
    while name!=all_a:
        a_z = ord('Z')-ord('A')
        ans += min(ord(name[loc])-ord('A'), a_z-(ord(name[loc])-ord('A'))+1)
        loc_next, cnt_next = func(name, loc)
        name[loc] = 'A'
        ans += cnt_next
        loc = loc_next
        
    
    return ans

print(solution('JEROEN'))