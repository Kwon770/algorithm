import sys; readline = sys.stdin.readline

N = int(readline())
A, B = map(int, readline().split())

ans = sys.maxsize
for i in range(N // B + 1):
    b = (B * i)
    a = N - b
    if a % A != 0:
        continue

    count = (a // A) + i
    ans = min(ans, count)

if ans == sys.maxsize:
    print(-1)
else:
    print(ans)