# https://programmers.co.kr/learn/courses/30/lessons/86052
# 월간 코드 챌린지 시즌3, 빛의 경로 사이클

# 처음 문제를 봤을 때, 중복 확인과 빛의 경로 시뮬레이션이 워낙 복잡하다고 느껴서 brainfuck 구현이라고 생각했다.
# 때문에 빛의 경로를 시뮬레이션하는 과정에서 모든 경로를 저장하고 있다가, 경로를 모두 알아내면 기존의 사이클의 모든 경로와 학인하여서 중복 여부를 파악했다.
# => 시간 초과

# ""노드를 통한 빛의 경로는 고정되어 있으므로, 하나의 경로라도 같다면 중복된 사이클이다"" 이론을 이용한 중복 확인 도입
# => 시간 초과

# 결과적으로는 각 사이클은 고유의 경로를 가진다는 점과 사이클은 결국 시작점으로 돌아온다는 점을 이용한 DFS 탐색을 사용해야했다.
# 경로로 방문여부를 확인했던 방법에서 노드별 싱하좌우 3차원 배열을 통한 방문 여부를 확인하며, 이미 방문한 경로에 대해서는 탐색할 필요가 없다.
# 재귀 DFS 과정에서 시작점으로 돌아온다면, 하나의 사이클이므로 답의 목록에 추가한다

# 재귀 깊이를 확장시키지 않으면 런타임 에러 발생한다.


import sys; sys.setrecursionlimit(10 ** 6)

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]


def rotateR(idx):
    idx += 1
    if idx == 4:
        idx = 0
    return idx


def rotateL(idx):
    idx -= 1
    if idx == -1:
        idx = 3
    return idx


def reflect(r, c, rotation):
    nr = r + dr[rotation]
    nc = c + dc[rotation]

    if nr >= R:
        nr = 0
    elif nr < 0:
        nr = R - 1

    if nc >= C:
        nc = 0
    elif nc < 0:
        nc = C - 1

    return [nr, nc]


def dfs(grid, start, r, c, rotation, distance):
    visited[rotation][r][c] = True

    nr, nc = reflect(r, c, rotation)
    if grid[nr][nc] == "R":
        rotation = rotateR(rotation)
    elif grid[nr][nc] == "L":
        rotation = rotateL(rotation)

    if start[0] == nr and start[1] == nc and start[2] == rotation:
        answer.append(distance)
        return

    if not visited[rotation][nr][nc]:
        dfs(grid, start, nr, nc, rotation, distance + 1)


def solution(grid):
    global answer, visited, R, C
    R = len(grid)
    C = len(grid[0])
    visited = [[[False] * C for _ in range(R)] for _ in range(4)]
    answer = []
    for r in range(R):
        for c in range(C):
            for rotation in range(4):
                dfs(grid, (r, c, rotation), r, c, rotation, 1)

    answer.sort()
    return answer