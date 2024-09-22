# https://www.acmicpc.net/problem/13656
# 13656 침식
# Memory: 146304 KB, Time: 2116 ms

# 좌표기반 DFS

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

M, N = map(int, readline().split())
fibers = []
for _ in range(M):
    fibers.append(input())
fibers.append('0' * N)

visited = [[False] * N for _ in range(M + 1)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
def dfs(x, y):
    global visited
    if fibers[x][y] == '1' or visited[x][y]:
        return

    visited[x][y] = True
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx > M or ny >= N:
            continue
        dfs(nx, ny)

for fy in range(N):
    dfs(0, fy)

penetrated = False
for ly in range(N):
    if visited[M][ly]:
        penetrated = True
        break
if penetrated:
    print("YES")
else:
    print("NO")