# https://www.acmicpc.net/problem/11559
# 11559 Puyo Puyo
# Memory : 30840 KB / Time : 68 ms

# 파괴될 블럭을 탐색하고 블럭을 떨어뜨려야하기 때문에, DFS와 그래프 탐색을 통해서 풀 수 있다.
# 그래프 탐색을 최적화할때 엣지케이스를 주의해야한다.

import sys; readline = sys.stdin.readline

ROW = 12
COLUMN = 6
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]


def getPuyosByDfs(row, col, visited):
    visited[row][col] = True
    puyo = [(row, col)]

    for i in range(4):
        nr = row + dr[i]
        nc = col + dc[i]
        if nr < 0 or nc < 0 or nr >= ROW or nc >= COLUMN \
                or visited[nr][nc] or field[nr][nc] != field[row][col]:
            continue

        puyo.extend(getPuyosByDfs(nr, nc, visited))
    return puyo

def explodePuyo(visited):
    for r in range(ROW):
        for c in range(COLUMN):
            if visited[r][c]:
                field[r][c] = '.'

def gravity():
    for c in range(COLUMN):
        for r in range(ROW - 1, -1, -1):
            if field[r][c] == '.':
                for fr in range(r, -1, -1):
                    if field[fr][c] != '.':
                        field[r][c], field[fr][c] = field[fr][c], field[r][c]
                        break


field = [list(input()) for _ in range(ROW)]

cnt = -1
exploded = True
while exploded:
    cnt += 1
    exploded = False

    visited = [[False for _ in range(COLUMN)] for _ in range(ROW)]
    for r in range(ROW):
        for c in range(COLUMN):
            if field[r][c] == '.' or visited[r][c]:
                continue

            puyo = getPuyosByDfs(r, c, visited)
            if len(puyo) >= 4:
                exploded = True
            else:
                for p in puyo:
                    visited[p[0]][p[1]] = False

    explodePuyo(visited)

    gravity()

print(cnt)