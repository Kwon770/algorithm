import sys; readline = sys.stdin.readline

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]


N, K = map(int, readline().split())
town = []
for _ in range(N):
    town.append(list(map(int, readline().split())))


visited = [[False for _ in range(N)] for _ in range(N)]
departments = [0] * (31)
for i in range(N):
    for j in range(N):
        if visited[i][j]:
            continue

        visited[i][j] = True
        cnt = 0
        stack = [(i,j)]
        while stack:
            cnt += 1
            r, c = stack.pop()
            for k in range(4):
                nr = r + dr[k]
                nc = c + dc[k]
                if nr < 0 or nc < 0 or nr >= N or nc >= N or town[nr][nc] != town[i][j] or visited[nr][nc]:
                    continue

                visited[nr][nc] = True
                stack.append((nr, nc))
        if cnt >= K:
            departments[town[i][j]] += 1

ans_val = 0
ans_num = 0
for i in range(1, 31):
    if departments[i] >= ans_val:
        ans_val = departments[i]
        ans_num = i
print(ans_num)
