# https://www.acmicpc.net/problem/15724
# 15724 주지수
# Memory: 73180 KB, Time: 920 ms

"""

"""""

# dp ??
# 150만 * 50

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N = int(input())
works = [(0,0)]
for n in range(N):
    t, p = map(int, readline().split())
    works.append((t, p))

dp = [0] * (N + 2) # for if in loop
for day in range(N, 0, -1):
    work = works[day]

    finish_day = day + work[0] - 1
    if finish_day > N:
        continue

    if work[1] + dp[finish_day + 1] > dp[day + 1]:
        dp[day] = work[1] + dp[finish_day + 1]
    else:
        dp[day] = dp[day + 1]
    print(dp)

print(dp[1])