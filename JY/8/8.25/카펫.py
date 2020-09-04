def solution(brown, yellow):
    answer = []
    for i in range(1, int(yellow**1/2)+2):

        if yellow%i==0:
            print(i,999)
            if brown==(((yellow//i)+2+ i+2)*2-4):
                return [yellow//i+2, i+2]