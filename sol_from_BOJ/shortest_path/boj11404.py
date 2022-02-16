# https://www.acmicpc.net/problem/11404
# Floyd warshall : 11404 플로이드
# Memory : 30864 KB , Time : 536 ms

# 플로이드 와샬 알고리즘을 그대로 사용하는 문제

import sys; input = sys.stdin.readline

INF = int(1e9)

def solution():
    n = int(input())
    m = int(input())
    graph = [[INF] * (n + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        graph[i][i] = 0

    for _ in range(m):
        a, b, c = map(int, input().split())
        if graph[a][b] == INF:
            graph[a][b] = c
        else:
            graph[a][b] = min(graph[a][b], c)

    for k in range(1, n + 1):
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

    for r in range(1, n + 1):
        for c in range(1, n + 1):
            if graph[r][c] == INF:
                print(0, end=" ")
            else:
                print(graph[r][c], end=" ")
        print()


solution()
