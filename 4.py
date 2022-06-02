import sys; readline = sys.stdin.readline

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]


def dfs(fr, fc, r, c, board, visited, ans):
    global n, m

    for i in range(4):
        nr = r + dr[i]
        nc = c + dc[i]
        if nr < 0 or nc < 0 or nr >= n or nc >= m or visited[nr][nc] or abs(nr - fr) >= 2 or abs(nc - fc) >= 2 or \
                board[nr][nc] == '2':
            continue

        visited[nr][nc] = True
        if board[nr][nc] == '1':
            ans.add((fr, fc))
            ans.add((nr, nc))

        dfs(fr, fc, nr, nc, board, visited, ans)


n, m = map(int, readline().split())
board = []
for i in range(n):
    board.append(list(readline().split()))

ans = set()
for r in range(n):
    for c in range(m):
        if board[r][c] == '1':
            visited = [[False] * m for _ in range(n)]
            visited[r][c] = True
            dfs(r, c, r, c, board, visited, ans)

print(len(ans))