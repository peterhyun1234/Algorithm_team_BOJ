N = int(input())
li = list(map(int, input().split()))

start = 0
end = N-1

def divide(start, end):
    mid = (start+end)//2
    if start==end:
        return [li[start],li[start]]
    else:
         left = divide(start, mid)
         right = divide(mid+1, end)
         return [left[0]+right[0], min