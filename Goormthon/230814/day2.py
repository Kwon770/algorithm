import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

N = int(readline())
T, M = map(int, readline().split())
for _ in range(N):
    c = int(readline())
    T += (M + c) // 60
    T %= 24
    M = (M + c) % 60

print(T, M)