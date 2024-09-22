"""
https://www.acmicpc.net/problem/12865
12865 평범한 배낭
Memory: 227036 KB, Time: 4548 ms

냅색, 배낭 문제
https://howudong.tistory.com/106

- dp[n번까지의 아이템을 판단했을때][용량 k에 넣을 수 있는] = 최대 가치
- 아이템 중복 안됨
"""""

import sys; readline = sys.stdin.readline

N, K = map(int, readline().split())
things = [(0,0)]
for _ in range(N):
    W, V = map(int, readline().split())
    things.append((W, V))

dp = [[0 for _ in range(K + 1)] for _ in range(N + 1)]
for n in range(1, N + 1):
    w, v = things[n]

    for k in range(1, K + 1):
        if k < w:
            dp[n][k] = dp[n - 1][k]
        else:
            dp[n][k] = max(dp[n - 1][k], dp[n - 1][k - w] + v)

print(dp[N][K])