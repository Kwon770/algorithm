import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]


N = int(readline())
town = []
for _ in range(N):
    town.append(list(readline().split()))

visited = [[False for _ in range(N)] for _ in range(N)]
ans = 0
for i in range(N):
    for j in range(N):
        if visited[i][j] or town[i][j] == '0':
            continue

        ans += 1
        visited[i][j] = True
        stack = [(i,j)]
        while stack:
            r, c = stack.pop()
            for k in range(4):
                nr = r + dr[k]
                nc = c + dc[k]
                if nr < 0 or nc < 0 or nr >= N or nc >= N or town[nr][nc] == '0' or visited[nr][nc]:
                    continue

                visited[nr][nc] = True
                stack.append((nr, nc))

print(ans)