s = input()
e = input()

ans = []

last_ch = e[-1]
elen = len(e)
slen = len(s)
for i in range(slen):
    ans.append(s[i])
    if ans[-1]==last_ch and len(ans)>=elen:
        is_ex = True
        for k in range(1, elen+1):
            if ans[-k] != e[-k]:
                is_ex = False
                break
        if is_ex:
            for _ in range(elen):
                ans.pop()
ans = ''.join(ans)
if ans:
    print(ans)
else:
    print('FRULA')
