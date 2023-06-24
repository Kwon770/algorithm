# https://www.acmicpc.net/problem/1647
# 1647 도시 분할 계획
# Memory: 195964 KB, Time: 3612 ms


"""
이 문제의 마을과 도로에 대한 사전 조건은 MST (Minimum Spanning Tree, 최소신장트리)임을 알아차릴 것을 요구하고,
- 임의의 두 집 사이에는 "경로"가 항상 존재
- 마을을 두 개의 분리된 마을로 분할할 계획이며, 분할된 마을안의 집끼리는 언제나 경로가 존재

최종적으로 요구하는 조건은 MST를 제대로 이해하고 있는지를 요구한다.
- 분리된 각 마을에는 집이 하나 이상이 있어야 함
- 분리된 마을끼리는 연결된 도로가 없애고, 각 마을안의 집끼리는 늘 경로가 있어야함
- 분리이후, 경로가 존재하기만 하면 되고 불필요한 도로는 전부 제거하여, 도로 유지비를 최소로 만듦

꽤나 노골적으로 MST를 드러내고 있으며, MST를 알고있고 구현할 줄 안다면 풀 수 있는 문제
MST를 구현하기 위해 두 개의 풀이가 있다. 전체적으로 그리디한 풀이다.
- 크루스칼 알고리즘 O(elog_2 e)  [e:edge]
  - 최소 비용의 간선을 우선적으로 선택하며, 사이클을 만들지 않는 간선만 선택
  - 선택할 간선이 사이클이 만드는 지를 find_parent와 union연산을 통해 확인
  - 스패닝 트리를 완성해나가는 느낌
- 프림 알고리즘 O(N^2)  [N:node]
  - (임의의) 시작 노드에서 부터, 최소의 비용의 노드들을 선택하며 확장해나감
  - 후보 간선의 목적지 노드가 이미 방문했던(추가했던) 노드라면, 사이클을 의미하므로 후보에 추가하지 않음 
  - 스패닝 트리를 확장해나가는 느낌

시간복잡도 상으로 대게 크루스칼이 빠르며 "크루스칼 알고리즘"을 사용하면 됨.
정말 예외적으로 간선이 많은 밀집 그래프라면, "프림 알고리즘"을 사용.

"""""

import sys;

readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
import heapq


def find(x):
    global parents

    if parents[x] != x:
        parents[x] = find(parents[x])

    return parents[x]


def union(a, b):
    global parents

    a = find(a)
    b = find(b)
    if a < b:
        parents[b] = a
    else:
        parents[a] = b


N, M = map(int, readline().split())
roads = []
for _ in range(M):
    A, B, C = map(int, readline().split())
    roads.append((C, A, B))
roads.sort()

parents = [i for i in range(N + 1)]
max_road = 0
total_road = 0
for C, A, B in roads:
    if find(A) == find(B):
        continue

    union(A, B)
    max_road = max(max_road, C)
    total_road += C

print(total_road - max_road)

""" 프림 알고리즘
N, M = map(int, readline().split())
roads = [[] for _ in range(N + 1)]
for _ in range(M):
    A, B, C = map(int, readline().split())
    roads[A].append((C, B))
    roads[B].append((C, A))

visited = [False] * (N + 1)
max_road = -1
total_road = 0
q = [(0, 1)]
while q:
    price, city = heapq.heappop(q)
    if visited[city]:
        continue

    max_road = max(max_road, price)
    total_road += price
    visited[city] = True
    for next_price, next_city in roads[city]:
        if visited[next_city]:
            continue

        heapq.heappush(q, (next_price, next_city))

print(total_road - max_road)
"""