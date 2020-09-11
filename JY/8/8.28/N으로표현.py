# 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
# 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
def solution(N, number):
    ans = 0
    s = [set() for _ in range(10)]
    s[1].add(N)
    cnt = 1
    while True:
        temp = set()
        if number in s[cnt]:
            break
        if cnt>8:
            return -1
        cnt += 1
        for k in range(1, cnt//2+1):
            for i in s[k]:
                for j in s[cnt-k]:
                    if i!=0:
                        temp.add(j//i)
                    if j!=0:
                        temp.add(i//j)
                    temp.add(i+j)
                    temp.add(i*j)
                    temp.add(i-j)
                    temp.add(j-i)
        temp.add(int(str(N)*cnt))
        s[cnt] = temp

    ans = cnt
    return ans