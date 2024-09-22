"""
https://school.programmers.co.kr/learn/courses/30/lessons/72413
2021 KAKAO BLIND > 합승 택시 요금

합승이라는 메커니즘과 합승하거나 안하거나의 최소 요금이라는 복잡한 조건을 주었지만,
결국은 최소 요금만 구하면 되므로 최단거리 알고리즘을 응용하는 문제였다.

다익스트라나 플로이드 와샬을 알고있으면 쉽게 풀 수 있다. (1시작 인덱스 조심해야한다)
"""

INF = 9876543210

def solution(n, s, a, b, fares):
    answer = 0
    s -= 1
    a -= 1
    b -= 1

    dist = [[INF for _ in range(n)] for _ in range(n)]
    for i in range(n):
        dist[i][i] = 0
    for c, d, f in fares:
        dist[c - 1][d - 1] = f
        dist[d - 1][c - 1] = f

    for mid in range(n):
        for start in range(n):
            for end in range(n):
                dist[start][end] = min(dist[start][end], dist[start][mid] + dist[mid][end])

    answer = dist[s][a] + dist[s][b]

    for together in range(n):
        cost = dist[s][together] + dist[together][a] + dist[together][b]
        answer = min(answer, cost)

    return answer