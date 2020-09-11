from copy import deepcopy
def solution(key, lock):
    m = len(key)
    n = len(lock)
    def clockwise(arr):
        arr.reverse()
        return list(map(list,zip(*arr)))

    for _ in range(4):
        for a in range(-n, n+1):    #필터 돌리기
            for b in range(-n, n+1):
                go_next=False
                for i in range(n):
                    for j in range(n):
                        if 0<=a+i<m and 0<=b+j<m:
                            if lock[i][j]^key[a+i][b+j]==0:
                                go_next=True
                                break
                        else:
                            if lock[i][j]==0:
                                go_next=True
                                break
                    if go_next:
                        break
                if not go_next:
                    return True
                
        key = clockwise(key)

    return False