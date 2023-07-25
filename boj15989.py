import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

dp = [1] * 10001

for i in range(2, 10001):
    dp[i] += dp[i - 2]

for i in range(3, 10001):
    dp[i] += dp[i - 3]

for _ in range(int(readline())):
    n = int(readline())
    print(dp[n])