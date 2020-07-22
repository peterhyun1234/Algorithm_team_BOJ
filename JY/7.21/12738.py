'''
N = int(input())

li = list(map(int, input().split()))

def bi_search(arr, num):
    lo = 0
    hi = len(arr)-1
    while lo<hi:
        mid = (lo+hi)//2
        if arr[mid] <num:
            lo = mid + 1
        else:
            hi = mid
    arr[lo] = num

def lis(arr):
    if not arr:
        return 0

    # C[i] means smallest last number of lis subsequences whose length are i
    INF = float('inf')
    C = [INF] * (len(arr)+1)
    C[0] = -INF
    C[1] = arr[0]
    tmp_longest = 1

    # Find i that matches C[i-1] < n <= C[i]
    def search(lo, hi, n):
        if lo == hi:
            return lo
        elif lo + 1 == hi:
            return lo if C[lo] >= n else hi

        mid = (lo + hi) // 2
        if C[mid] == n:
            return mid
        elif C[mid] < n:
            return search(mid+1, hi, n)
        else:
            return search(lo, mid, n)


    for n in arr:
        if C[tmp_longest] < n:
            tmp_longest += 1
            C[tmp_longest] = n
        else:
            next_loc = search(0, tmp_longest, n)
            C[next_loc] = n

    return tmp_longest

print(lis(li))
'''
import sys
input = sys.stdin.readline

def lower_bound(arr, num):
    lo = 0; hi = len(arr) - 1
    while lo < hi:
        mid = (lo + hi) // 2
        if arr[mid] < num:
            lo = mid + 1
        else:
            hi = mid
    arr[lo] = num

n = int(input())
l = list(map(int, input().split()))
arr = [l[0]]

for i in range(1, n):
    if l[i] > arr[-1]:
        arr.append(l[i])
    else:
        lower_bound(arr, l[i])
print(len(arr))