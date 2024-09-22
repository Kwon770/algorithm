# https://www.acmicpc.net/problem/2573
# 2573 빙산
# Memory: 35364 KB, Time: 1416 ms, python3
# Memory: 215838 KB, Time: 1520 ms, pypy3

"""
매 스탭마다 빙산을 녹이고, 녹은 빙산의 갯수를 BFS로 확인한다.

1. 문제는 매 스탭 한 순간을 기준으로 녹이는 양을 정하기 때문에, 한 배열에 녹은 양을 저장하면서 녹일 양을 계산한다면, 실제와 달라진다
또 녹은 이후의 빙산의 갯수를 세어려야 하므로, BFS를 두 번씩 돌려야만 했다.

2. 1초라는 빡빡한 시간 조건때문에, pypy3로 제출해야만 통과한다.
다음 단계에서 빙산을 녹이는 동시에 이전 단계에서의 빙산의 갯수를 구하는 방법도 있지만, 이 또한 배열을 2개로 복사해서 계산해야 하므로
마찬가지로 시간이 오래 걸린다. 아예 풀이를 비틀어야 python3로 통과가능하다.

=> python3로 통과하려면, 빙산을 녹이기 위해 배열 전체를 순회해선 안되고 배열 2개를 써선 안된다.
3. 배열 전체를 순회하지 말고, 빙산의 위치를 저장한 set으로 필요한 곳만 확인한다.
중간에 빙산이 녹아버렸을 때, 녹은 빙산의 위치를 리스트에서 제거하는 것에 시간 소모가 클 것이라고 생각해서 이 방식을 진행하지 않았지만,
!! set의 remove를 사용하면 O(1)안에 가능하다. !!
!! 단, set을 순회하는 중에 원소를 변경하면 오류가 발생하므로, copy본으로 순회해야 한다 !!

4. visited를 이용해서 2번의 문제를 해결할 수 있다.
빙산을 녹이는 과정에서 빙산이 0이 되었더라도 visited를 통해 방문한 빙산을 표시하면, 바다의 갯수를 세아리는 과정에서 문제가 발생하지 않는다.
그래서 바다는 visited처리하지 않고 바다만 visited처리 한다.  

"""""

import sys;

readline = sys.stdin.readline
import copy

# sys.setrecursionlimit(10 ** 5)

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

N, M = map(int, readline().split())
arr = []
ice = set()
for i in range(N):
    l = list(map(int, readline().split()))
    for j in range(M):
        if l[j] != 0:
            ice.add((i, j))
    arr.append(l)


def bfs(i, j):
    global visited, arr, ice

    q = [(i, j)]
    visited[i][j] = True
    while q:
        r, c = q.pop()

        for k in range(4):
            nr = r + dr[k]
            nc = c + dc[k]

            if not visited[nr][nc]:
                if arr[nr][nc] == 0 and arr[r][c] > 0:
                    arr[r][c] -= 1

                if arr[nr][nc] != 0:
                    visited[nr][nc] = True
                    q.append((nr, nc))

        if arr[r][c] == 0:
            ice.remove((r, c))


time = 0
while True:
    cnt = 0
    visited = [[False] * M for _ in range(N)]
    ice_copy = ice.copy()

    for i, j in ice_copy:
        if arr[i][j] != 0 and not visited[i][j]:
            bfs(i, j)
            cnt += 1

    if cnt >= 2:
        print(time)
        break

    if cnt == 0:
        print(0)
        break

    time += 1

# N, M = map(int, readline().split())
# arr = []
# ice = set()
# for i in range(N):
#     l = list(map(int, readline().split()))
#     for j in range(M):
#         if l[j] != 0:
#             ice.add((i, j))
#     arr.append(l)
#
# def check():
#     visited = [[False for _ in range(M)] for _ in range(N)]
#     cnt = 0
#     for r in range(N):
#         for c in range(M):
#             if ice[r][c] == 0 or visited[r][c]:
#                 continue
#
#             cnt += 1
#             q = [(r, c)]
#             while q:
#                 row, col = q.pop()
#
#                 for i in range(4):
#                     nr = row + dr[i]
#                     nc = col + dc[i]
#                     if nr < 0 or nc < 0 or N <= nr or M <= nc or visited[nr][nc] or ice[nr][nc] == 0:
#                         continue
#
#                     visited[nr][nc] = True
#                     q.append((nr, nc))
#     return cnt
#
#
# time = 0
# while True:
#     time += 1
#
#     ice_copy = [ice[r][:] for r in range(N)]
#     for r in range(N):
#         for c in range(M):
#             if ice_copy[r][c] == 0:
#                 for i in range(4):
#                     nr = r + dr[i]
#                     nc = c + dc[i]
#                     if nr < 0 or nc < 0 or N <= nr or M <= nc:
#                         continue
#
#                     if ice[nr][nc] > 0:
#                         ice[nr][nc] -= 1
#
#     cnt = check()
#     if cnt >= 2:
#         print(time)
#         break
#
#     if cnt == 0:
#         print(0)
#         break