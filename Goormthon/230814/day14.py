import sys; readline = sys.stdin.readline

N, M, K = map(int, readline().split())
edges = [[False for _ in range(N + 1)] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, readline().split())
    edges[a][b] = True
    edges[b][a] = True

visited = [False for _ in range(N + 1)]
node = K
cnt = 1
stop = False

while True:
    visited[node] = True

    stop = True
    for i in range(1, N + 1):
        if edges[node][i] and not visited[i]:
            stop = False
            node = i
            cnt += 1
            break
    if stop: break

print(cnt, node)