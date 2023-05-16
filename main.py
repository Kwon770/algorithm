# https://www.acmicpc.net/problem/2121
# 넷이 놀기, 2121
# Memory: 111128 KB, Time: 1364 ms

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N = int(readline())
A, B = map(int, readline().split())
pos = set()
for _ in range(N):
    x, y = map(int, readline().split())
    pos.add((x, y))

ans = 0
for p in pos:
    if (p[0] + A, p[1]) in pos and \
            (p[0], p[1] + B) in pos and \
            (p[0] + A, p[1] + B) in pos:
        ans += 1

print(ans)
