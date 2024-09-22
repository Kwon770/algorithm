"""
https://www.acmicpc.net/problem/14938
14938 서강그라운드
Memory: 31220 KB, Time: 424 ms

다익스트라로도 풀 수 있지만, 플로이드와샬로 짧게 풀리는 문제.
문제에서도 간단히 떠올릴 수 있었다. 
"""""
import heapq
INF = 9876543210

n, m = map(int, input().split())
lines = []
ans = set()
graph = [[INF for _ in range(n + 1)] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    lines.append((a, b, c))
    ans.add((a,b))
    graph[a][b] = c
    graph[b][a] = c
lines.sort(key= lambda x: (-x[2], x[0], x[1]))


def dijkstra(start):
    distances = [INF] * (n + 1)

    q = [(0, start)]
    while q:
        cost, now = heapq.heappop(q)

        for next in range(n + 1):
            if graph[now][next] == INF: continue

            if cost + graph[now][next] < distances[next]:
                distances[next] = cost + graph[now][next]
                heapq.heappush(q, (distances[next], next))

    return distances

original_network = dijkstra(1)
for a, b, cost in lines:
    tmp = graph[a][b]
    graph[a][b] = INF
    graph[b][a] = INF
    new_network = dijkstra(1)

    broken = False
    for i in range(2, n + 1):
        if new_network[i] > original_network[i]:
            graph[a][b] = tmp
            graph[b][a] = tmp
            broken = True
            break

    if not broken:
        ans.remove((a, b))


print(len(ans))
for a in ans:
    print(f"{a[0]} {a[1]}")


li
l = zip(*li[::-1])
[list(e) for e in l]

# n, m = map(int, input().split())
# lines = []
# for _ in range(m):
#     a, b, c = map(int, input().split())
#     lines.append([c, a, b])
# lines.sort(key=lambda a: (a[0], a[1], a[2]))
#
#
# parents = [i for i in range(0, n + 1)]
#
# def get_parent(x):
#     if parents[x] == x:
#         return x
#
#     parents[x] = get_parent(parents[x])
#     return parents[x]
#
# def union_find(x, y):
#     x = get_parent(x)
#     y = get_parent(y)
#
#     if x < y:
#         parents[y] = x
#     else:
#         parents[x] = y
#
# def is_cycled(x, y):
#     return get_parent(x) == get_parent(y)
#
#
# ans = []
# for cost, a, b in lines:
#     if not is_cycled(a, b):
#         union_find(a, b)
#         ans.append((a,b))
#
# print(len(ans))
# for a in ans:
#     print(*a, sep=" ")