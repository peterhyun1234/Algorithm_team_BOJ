def solution(p):
    ans = ''
    n = len(p)
    def check(u):
        cnt = 0
        for i in u:
            if i == '(':
                cnt+=1
            else:
                cnt-=1
            if cnt<0:
                return False
        return True
    def func(s):
        ans = ''
        if s=='':
            return ''
        n = len(s)
        count = 0
        for i in range(n):
            if s[i]=='(':
                count +=1
            else:
                count -= 1
            if count == 0:
                u = s[:i+1]
                v = s[i+1:]
                if check(u):
                    ans += u
                    ans += func(v)
                else:
                    ans += '('
                    ans += func(v)
                    ans += ')'
                    for j in u[1:-1]:
                        if j=='(':
                            ans += ')'
                        else:
                            ans += '('
                break
        return ans
    ans = func(p)
                    
    return ans