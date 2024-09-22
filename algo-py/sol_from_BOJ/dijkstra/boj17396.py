# https://www.acmicpc.net/problem/17396
# 17396 백도어
# Memory : 117924 KB / Time : 836 ms

# 문제 자체는 어려운 다익스트라가 아니지만, (N <= 100,000, M <= 300,000)으로
# 탐색 횟수가 상당히 큰 케이스다. 따라서 다음을 조심해야 한다.

# 1. 불필요한 탐색을 없애기 위해, 이동불가한 분기점의 간선은 애초에 배제한다.
# 2. INF는 9876543210, int(1e9)로 충분하지 않다.
# sys.maxsize로 해야 충분하였다. 그렇지 않으면 틀린다.
# 3. 파이썬의 경우 불필요한 연산자 사용(e.g. in) 는 TLE를 일으킨다.


import sys; readline = sys.stdin.readline
import heapq
INF = sys.maxsize
N, M = map(int, readline().split())

ways = [[] for _ in range(N)]
sights = list(map(int, readline().split()))
sights[N - 1] = 0

for _ in range(M):
    a, b, t = map(int, readline().split())
    if sights[a] or sights[b]:
        continue

    ways[a].append((t, b))
    ways[b].append((t, a))

distance = [INF] * (N)
distance[0] = 0
q = [(0, 0)]
while q:
    dist, now = heapq.heappop(q)
    if distance[now] < dist:
        continue

    for node in ways[now]:
        cost = distance[now] + node[0]
        if distance[node[1]] > cost:
            distance[node[1]] = cost
            heapq.heappush(q, (cost, node[1]))

if distance[N - 1] == INF:
    print(-1)
else:
    print(distance[N - 1])