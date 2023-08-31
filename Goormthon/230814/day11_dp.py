import sys; readline = sys.stdin.readline

N = int(input())
A, B = map(int, input().split())

dp = [sys.maxsize] * (N + 1)
dp[0] = 0

for i in range(N + 1):
    if i - A >= 0:
        dp[i] = min(dp[i], dp[i - A] + 1)
    if i - B >= 0:
        dp[i] = min(dp[i], dp[i - B] + 1)

print(dp[N] if dp[N] != sys.maxsize else -1)