import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N, M = map(int, readline().split())
arr = []
dp = [[0] for _ in range(N + 1)]
for i in range(N):
    l = list(map(int, readline().split()))
    dpdp = 0
    for ll in l:
        dpdp += ll
        dp[i + 1].append(dpdp)
    arr.append(l)

K = int(input())
for _ in range(K):
    x1, y1, x2, y2 = map(int, readline().split())

    total = 0
    for x in range(x1, x2 + 1):
        total += dp[x][y2] - dp[x][y1 - 1]
    print(total)