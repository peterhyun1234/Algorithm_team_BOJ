num = input()
N = int(num)
start = max(N-9*len(num), 0)
ans = 0

for i in range(start,N):
    a = sum(map(int, str(i))) +i

    if a == N:
        ans = i
        break

print(ans)