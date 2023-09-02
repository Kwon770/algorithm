# https://www.acmicpc.net/problem/10775
# 10775 공항
# Memory: 35108 KB, Time: 144 ms, python3

"""

"""""

import sys; readline = sys.stdin.readline

N, K = map(int, readline().split())
fruit = []
for i in range(N):
    p, c = map(int, readline().split())
    fruit.append([c // p, p])

full = 0
fruit.sort(reverse=True)
for i in range(N):
    if fruit[i][1] <= K:
        full += fruit[i][0] * fruit[i][1]
        K -= fruit[i][1]

    else:
        full += fruit[i][0] * K
        K = 0

    if K <= 0:
        break

print(full)