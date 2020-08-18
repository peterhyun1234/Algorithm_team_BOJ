import sys
input = sys.stdin.readline

n = int(input())
li = list(map(int, input().split()))
arr = [li[0]]
def lower_bound(li,target):
    start = 0
    end = len(li)-1
    while start<end:
        mid = (start+end)//2
        if li[mid] >=target:
            end = mid
        else:
            start = mid +1
    return end

for i in li:
    if arr[-1]<i:
        arr.append(i)
    else:
        arr[lower_bound(arr, i)] = i
print(len(arr))