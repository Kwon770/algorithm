"""
https://school.programmers.co.kr/learn/courses/30/lessons/72413
2021 KAKAO BLIND > 합승 택시 요금

합승이라는 메커니즘과 합승하거나 안하거나의 최소 요금이라는 복잡한 조건을 주었지만,
결국은 최소 요금만 구하면 되므로 최단거리 알고리즘을 응용하는 문제였다.

다익스트라나 플로이드 와샬을 알고있으면 쉽게 풀 수 있다. (1시작 인덱스 조심해야한다)
"""


import heapq

INF = 9876543210

def dijksta(start, n, graph):
    distance = [INF] * n
    distance[start] = 0
    queue = []
    heapq.heappush(queue, (distance[start], start))

    while queue:
        dist, node = heapq.heappop(queue)
        if dist > distance[node]:
            continue

        for next in range(n):
            cost = dist + graph[node][next]
            if cost < distance[next]:
                distance[next] = cost
                heapq.heappush(queue, (cost, next))

    return distance


def solution(n, s, a, b, fares):
    answer = INF
    s -= 1
    a -= 1
    b -= 1

    graph = [[INF for _ in range(n)] for _ in range(n)]
    for c, d, f in fares:
        graph[c - 1][d - 1] = f
        graph[d - 1][c - 1] = f

    a_dist = dijksta(a, n, graph)
    b_dist = dijksta(b, n, graph)
    s_dist = dijksta(s, n, graph)

    for i in range(n):
        answer = min(answer, s_dist[i] + a_dist[i] + b_dist[i])

    return answer