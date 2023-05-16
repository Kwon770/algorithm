from itertools import combinations, permutations
from collections import deque
import heapq

INF = int(1e9)

# from collections import deque
# import heapq
# import math
#
# print(math.gcd(2,5))
# print(math.lcm(2,5))
#
# q = []
# heapq.heappush(q, 2)
# print(heapq.heappop(q))
#
# # a=[(1,2),(2,2),(4,1)]
# # a=sorted(a, key=lambda x: (x[1], x[0]))
# # print(a)

def dfs(graph, v, visited):
    # graph, a에서 갈 수 있는 인접 노드들, 인접 행렬
    visitied[v] = True
    for node in graph[v]:
        if not visited[node]:
            dfs(graph, node, visited)

def bfs(n):
    # graph, a에서 갈 수 있는 인접 노드들, 인접 행렬
    visited = [False] * (n+1)
    queue = deque([start])
    visited[start] = True
    while queue:
        now = queue.popleft()
        for node in graph[now]:
            if not visited[node]:
                queue.append(node)
                visited[node] = True

def dijkstra(start):
    # graph, a에서 갈 수 있는 인접 노드들, 인접 행렬
    distance = [INF] * (n+1)

    q = [(0, start)]
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue

        for node in graph[now]:
            cost = distance[now] + node[0]
            if distance[node[1]] > cost:
                distance[node[1]] = cost
                heapq.heappush(q, (cost, node[1]))

def floyd():
    # graph, a to b의 가중치, 2d arr
    for k in range(1, n+1):
        for a in range(1, n+1):
            for b in range(1, n+1):
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])


def bellman(start):
    # edges, (a, b, val), 1d arr
    for i in range(v):
        for j in range(e):
            a, b, c = edges[j]

            if distance[b] > distance[a] + c:
                distance[b] = distance[a] + c
                if i == v - 1:
                    return False # 사이클
    return True