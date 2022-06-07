# https://www.acmicpc.net/problem/1303
# 1303 전쟁 - 전투
# Memory : 30840 KB / Time : 96 ms

# 단순한 DFS 문제인데, 일반적인 입력과 다르게 가로, 세로 순으로 입력되서 잠시 헷갈렸다.

# C에서 쓰던 배열을 이용한 근접좌표 이동량 순회와 다르게 in 다음에 튜플 형식으로 for 문에 넣는 방식을 참고했다
# DFS에서 계산할 값을 전역, 출력매개변수에 하기보다는 내부에서 반환 값으로 처리하는 식으로 바꿨다.
# DFS에서 반환값의 흐름을 생각해보자

import sys; readline = sys.stdin.readline

def dfs(r, c, team):
    global visited

    cnt = 1
    for dr, dc in (-1,0),(0,1),(1,0),(0,-1):
        nr = r + dr
        nc = c + dc
        if nr < 0 or nc < 0 or nr >= M or nc >= N or visited[nr][nc] or g[nr][nc] != team:
            continue

        visited[nr][nc] = True
        cnt += dfs(nr, nc, team)
    return cnt


N, M = map(int, readline().split())
g = []
for _ in range(M):
    g.append(input())

visited = [[False] * N for _ in range(M)]
alias, enemy = 0, 0
for i in range(M):
    for j in range(N):
        if visited[i][j]:
            continue

        visited[i][j] = True
        cnt = dfs(i, j, g[i][j])

        if g[i][j] == 'W':
            alias += cnt ** 2
        else:
            enemy += cnt ** 2

print(alias, enemy)