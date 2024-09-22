# https://www.acmicpc.net/problem/10775
# 10775 공항
# Memory: 35108 KB, Time: 144 ms, python3

"""

"""""

import sys; readline = sys.stdin.readline

dr = {
    "U": -1,
    "R": 0,
    "D": 1,
    "L": 0
}

dc = {
    "U": 0,
    "R": 1,
    "D": 0,
    "L": -1
}

dmark = {
    "U": 0,
    "R": 1,
    "D": 0,
    "L": 1
}


def mark_arr(r, c, d):

    while r >= 0 and c >= 0 and r < N and c < N:
        arr[r][c][dmark[d]] += 1
        r += dr[d]
        c += dc[d]


N, M = map(int, readline().split())
arr =[[[0,0] for _ in range(N)] for _ in range(N)]
for _ in range(M):
    y, x, d = readline().split()
    mark_arr(int(y) - 1, int(x) - 1, d)

ans = 0
for i in range(N):
    for j in range(N):
        ans += arr[i][j][0] * arr[i][j][1]
print(ans)