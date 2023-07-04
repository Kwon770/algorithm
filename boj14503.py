import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

N, M = map(int, readline().split())
r, c, d = map(int, readline().split())
# r -= 1
# c -= 1
arr = []
for i in range(N):
    arr.append(list(map(int, readline().split())))

ans = 0
cleaned = [[False] * M for _ in range(N)]
end = False
while not end:
    if not cleaned[r][c]:
        cleaned[r][c] = True
        ans += 1
        continue

    cleanable = False
    for i in range(1, 5):
        nd = (d - i) % 4
        nr = r + dr[nd]
        nc = c + dc[nd]
        if nr < 0 or nc < 0 or nr >= N or nc >= M or arr[nr][nc] == 1:
            continue
        if not cleaned[nr][nc]:
            cleanable = True

            d = nd
            r = nr
            c = nc
            break

    if not cleanable:
        back_d = (d + 2) % 4
        nr = r + dr[back_d]
        nc = c + dc[back_d]
        if nr < 0 or nc < 0 or nr >= N or nc >= M or arr[nr][nc] == 1:
            end = True
            continue

        r = nr
        c = nc

print(ans)