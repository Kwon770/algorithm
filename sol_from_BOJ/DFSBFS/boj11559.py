# https://www.acmicpc.net/problem/11559
# 13549 숨바꼭질 3
# Memory : 50136 KB / Time : 672 ms

# 처음에 BFS를 사용했지만, 방문 검사를 빠드려서 TLE가 떠서, DP로 해결했었다. 쓸데없이 빙 둘러갔다.

# 계산은 불가한 문제 -> 탐색해야 함
# 1. BFS
# 1-1. priorityQueue BFS : 최단시간 경우를 먼저 BFS 탐색
# 1-2. 0-1 BFS : 가중치가 0과 1뿐인경우로, 0이면 front 1이면 back에 넣는 탐색
# 2. 다익스트라

# 1, 2번 모두 결국 큰 맥락은 같다. 0-1BFS는 신선한 접근 방식이였다.

import sys; readline = sys.stdin.readline
import heapq


# PriorityQueue BFS

MAX = 100000
CAPA = 200000
N, K = map(int, input().split())

visited = [False for _ in range(CAPA + 1)]
visited[N] = True
pq = [(0, N)]

while pq:
    time, now = heapq.heappop(pq)
    if now == K:
        print(time)
        break

    if now * 2 <= CAPA and not visited[now * 2]:
        heapq.heappush(pq, (time, now * 2))
        visited[now * 2] = True

    if now + 1 <= MAX and not visited[now + 1]:
        heapq.heappush(pq, (time + 1, now + 1))
        visited[now + 1] = True

    if now - 1 >= 0 and not visited[now - 1]:
        heapq.heappush(pq, (time + 1, now - 1))
        visited[now - 1] = True


# 다익
#
# INF = float('inf')
# MAX = 100000
# N, K = map(int, input().split())
#
# cost = [INF]*(2*MAX+1)
# cost[N] = 0
# pq = [(0, N)]
#
# while pq:
#     time, now = heapq.heappop(pq)
#     if time > cost[now]:
#         continue
#
#     for i in range(3):
#         ntime, nnow = time, now
#         if i == 0:
#             nnow *= 2
#         elif i == 1:
#             ntime += 1
#             nnow += 1
#         else:
#             ntime += 1
#             nnow -= 1
#
#         if 0 <= nnow <= 2*MAX and ntime < cost[nnow]:
#             cost[nnow] = ntime
#             heapq.heappush(pq, (ntime, nnow))
# print(cost[K])