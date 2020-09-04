from itertools import combinations

L, C = map(int, input().split())
li = input().split()
vowel = ['a', 'e', 'i', 'o', 'u']
ans_li = []
for i in combinations(li, L):
    i = list(i)
    count_vo = 0
    count_co = 0
    for j in i:
        if j in vowel:
            count_vo +=1
        else:
            count_co +=1
    if count_vo>=1 and count_co>=2:
        ans_li.append(''.join(sorted(i)))

for i in sorted(ans_li):
    print(i)
