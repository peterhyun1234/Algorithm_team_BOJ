import sys

input = sys.stdin.readline
i = 1
while True:
    P, L, V = map(int, input().split())
    if P==0 and L==0 and V==0:
        break
    k = V//L
    count = 0
    count += k*P

    if V%L>P:
        count += P
    else:
        count += V%L
    print(f"Case {i}: {count}")
    i += 1