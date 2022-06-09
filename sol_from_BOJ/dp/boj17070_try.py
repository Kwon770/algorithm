# https://www.acmicpc.net/problem/17070
# 17070 파이프 옮기기 1
# Memory : 32508 KB / Time : 92 ms

import sys; readline = sys.stdin.readline
from collections import deque

moving = [
    [(0,1,0), (1,1,2)],
    [(1,0,1), (1,1,2)],
    [(0,1,0), (1,0,1), (1,1,2)]
]

moving_scope = [
    [(0,0)], [(0,0)], [(0,0),(-1,0),(0,-1)]
]


N = int(readline())
home = [list(map(int, readline().split())) for _ in range(N)]
cache = [[[0,0,0] for _ in range(N)] for _ in range(N)]

cache[0][1][0] = 1
for r in range(N):
    for c in range(N):
        if r == N - 1 and c == N - 1:
            break

        for moving_dir, move in enumerate(moving):
            if cache[r][c][moving_dir] == 0:
                continue

            for moving_type, (dr, dc, nd) in enumerate(move):
                nr = r + dr
                nc = c + dc

                broken = False
                for scope_r, scope_c in moving_scope[nd]:
                    tr = nr + scope_r
                    tc = nc + scope_c

                    if tr < 0 or tc < 0 or tr >= N or tc >= N or home[tr][tc] == 1:
                        broken = True
                        break
                if broken: continue

                cache[nr][nc][nd] += cache[r][c][moving_dir]

print(sum(cache[N - 1][N - 1]))