# https://www.acmicpc.net/problem/17086
# 17086 아기 상어2
# Solution] Memory : 32404 KB / Time : 4980 ms
# Best Solution] Memory : 32404 KB / Time : 772 ms

# 모든 칸에서의 거리를 계산해야하며, N <= 50 정도로 그렇게 크지않아서 완전 탐색으로 가능하다.
# 단, 최적화 포인트가 있는데,
# 1. 상어들의 위치를 따로 배열에 관리해서, 바로 거리를 계산한다.
#    BFS로 가까운 상어의 위치를 계산할 수도 있는데, 저장된 상어들의 위치로 거리를 계산하는 것이
#    복잡도나 풀이속도 모두 고려하면 더 효과적이라고 판단된다.
# 2. 거리 계산은 단순 수학 계산으로 충분하다. 상하좌우대각선 모두 한 칸이므로,
#    dist = r_gap과 c_gap의 공통부분 + r_gap과 c_gap 중 더 큰 것의 더 큰 부분
#    으로 생각할 수 있는데, 이는 결국 r_gap과 c_gap 중 더 큰 값이 계산 결과인 것을 알 수 있다.

import sys; readline = sys.stdin.readline
from collections import deque

# def best_solution():
#     N, M = map(int, readline().split())
#     space = [list(map(int, readline().split())) for _ in range(N)]
#     sharks = []
#     for r in range(N):
#         for c in range(M):
#             if space[r][c] == 1:
#                 sharks.append((r, c))
#
#     safe_dist = -1
#     for r in range(N):
#         for c in range(M):
#             if space[r][c] == 1:
#                 safe_dist = max(safe_dist, 0)
#                 continue
#
#             close_shark_dist = 9876543210
#             for shark in sharks:
#                 shark_r, shark_c = shark
#
#                 r_gap = abs(r - shark_r)
#                 c_gap = abs(c - shark_c)
#                 dist = max(r_gap, c_gap)
#                 close_shark_dist = min(close_shark_dist, dist)
#
#             safe_dist = max(safe_dist, close_shark_dist)
#
#     return safe_dist

def solution():
    N, M = map(int, readline().split())
    space = [list(map(int, readline().split())) for _ in range(N)]
    sharks = []
    for r in range(N):
        for c in range(M):
            if space[r][c] == 1:
                sharks.append((r, c))

    max_dist = -1
    for r in range(N):
        for c in range(M):
            if space[r][c] == 1:
                max_dist = max(max_dist, 0)
                continue

            safe_dist = 9876543210
            for shark in sharks:
                s_r, s_c = shark
                dist = 0
                while s_r != r or s_c != c:
                    dist += 1
                    if s_r > r:
                        s_r -= 1
                    elif s_r < r:
                        s_r += 1

                    if s_c > c:
                        s_c -= 1
                    elif s_c < c:
                        s_c += 1

                safe_dist = min(safe_dist, dist)
            max_dist = max(max_dist, safe_dist)

    return max_dist

print(solution())