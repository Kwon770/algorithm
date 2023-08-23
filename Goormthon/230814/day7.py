import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

dr = [-1, -1, 0, 1, 1, 1, 0, -1]
dc = [0, 1, 1, 1, 0, -1, -1, -1]

def mark(r, c):
    global arr

    for i in range(8):
        nr = r + dr[i]
        nc = c + dc[i]
        if nr < 0 or nc < 0 or nr >= N or nc >= N or game[nr][nc] == '1':
            continue

        arr[nr][nc] += 1

N, K = map(int, readline().split())
arr = [[0 for _ in range(N)] for _ in range(N)]
game = []
for i in range(N):
    game.append(list(readline().split()))

for i in range(N):
    for j in range(N):
        if game[i][j] == '1':
            mark(i, j)

ans = 0
for i in range(N):
    for j in range(N):
        if arr[i][j] == K:
            ans += 1
print(ans)