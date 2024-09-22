# https://www.acmicpc.net/problem/2583
# 2583 영역 구하기
# Memory : 32412 KB / Time : 104 ms

# 단순한 그래프 탐색문제이지만, 표의 좌표기준을 오인해서 시간이 조금 걸렸다.
# 1. 0,0 이 왼쪽아래이고, N,M이 우측위다. 일반적인 배열의 좌표 설정과 다름을 유의해야한다.
#    물론 우리는 영역 개수와 넓이만 알면되므로, 좌표를 변환할 필요없이 초기값세팅만 주의하면 된다.
# 2. 좌표 기준이 표의 칸이 아니라 점기준이다.
#    잘못보면 (M+1 x N+1)만큼의 표로 오인할 수도 있다. 주어진 예제와 그림을 잘 보고 선택해야한다.
#    점의 좌표가 range(이상, 미만)과는 잘 떨어져서 코드가 복잡해지지는 않는다.

import sys; readline = sys.stdin.readline
from collections import deque

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

def bfs(r, c):
    area = 0
    q = deque([(r,c)])
    while q:
        row, col = q.popleft()
        if arr[row][col] == 1:
            continue

        arr[row][col] = 1
        area += 1

        for d in range(4):
            nr = row + dr[d]
            nc = col + dc[d]
            if nr < 0 or nc < 0 or nr >= M or nc >= N or arr[nr][nc] == 1:
                continue

            q.append((nr,nc))
    areas.append(area)


def solution():
    global cnt, areas, arr, N, M

    M, N, K = map(int, readline().split())
    arr = [[0] * (N) for _ in range(M)]
    for _ in range(K):
        ldx, ldy, rux, ruy = map(int, readline().split())
        for r in range(ldy, ruy):
            for c in range(ldx, rux):
                arr[r][c] = 1

    cnt = 0
    areas = []
    for r in range(M):
        for c in range(N):
            if arr[r][c] == 1:
                continue

            bfs(r, c)
            cnt += 1

    print(cnt)
    areas.sort()
    print(" ".join(map(str, areas)))

solution()