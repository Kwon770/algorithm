# (r,c) from 1

import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

dr = [0, -1, 0, 1, 0]
dc = [0, 0, 1, 0, -1]

N, K = map(int, readline().split())
arr = []
for _ in range(N):
    arr.append(list(readline().split()))
bombs = [[0 for _ in range(N)] for _ in range(N)]

for _ in range(K):
    r, c = map(int, readline().split())
    r -= 1
    c -= 1

    for i in range(5):
        nr = r + dr[i]
        nc = c + dc[i]
        if nr < 0 or nc < 0 or nr >= N or nc >= N or arr[nr][nc] == '#':
            continue

        if arr[nr][nc] == '0':
            bombs[nr][nc] += 1
        elif arr[nr][nc] == '@':
            bombs[nr][nc] += 2

ans = -1
for i in range(N):
    ans = max(ans, max(bombs[i]))
print(ans)