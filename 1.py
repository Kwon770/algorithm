import sys; readline = sys.stdin.readline

n, k = map(int, readline().split())
moves = [0] * n
for m in list(map(int, readline().split())):
    moves[m - 1] += 1

mn = min(moves)
ans = 0
for i in range(n):
    if mn == moves[i]:
        ans += (i + 1)

print(ans)