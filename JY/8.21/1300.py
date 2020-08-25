N = int(input())
k = int(input())
start = 1
end = N**2



while start<end:
    mid = (start+end)//2
    count = 0
    for i in range(1, N+1):
        limit = mid//i
        if limit>N:
            count += N
        else:
            count += limit
    if k<=count:
        end = mid
    else:
        start = mid + 1

print(end)
