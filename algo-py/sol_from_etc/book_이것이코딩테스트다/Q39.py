# ShortestPath - Q39 화성탐사 (P388)
# 문제 링크 : https://sckwon770.notion.site/Q39-437fa293a3d945a585b92b3cb3612285

# 문제와 (그래프 + 최단/최소) 단서에서 다익스트라를 떠올릴 수 있다.
    # BFS/DFS를 이용할 수 없다. 경로 중에서 최소 가중치인 경로를 찾아야하는데, DFS/BFS는 한 번 탐색한 노드는 더이상 탐색하지않는다.
# 2차원 형태의 가중치를 이용하여 다익스트라를 구현하면 됨.

import sys; input = sys.stdin.readline
import heapq

INF = int(1e9)

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

def solution():
    global N, mars, graph

    for T in range(int(input())):
        N = int(input())
        mars = []
        for r in range(N):
            arr = list(map(int, input().split()))
            mars.append(arr)

    q = [(mars[0][0], 0, 0)]
    distance = [[INF] * N for _ in range(N)]
    distance[0][0] = mars[0][0]
    while q:
        dist, r, c = heapq.heappop(q)
        if distance[r][c] < dist:
            continue

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]
            if nr < 0 or nc < 0 or nr >= N or nc >= N:
                continue

            cost = dist + mars[nr][nc]
            if cost < distance[nr][nc]:
                distance[nr][nc] = cost
                heapq.heappush(q, (cost, nr, nc))

    return distance[N-1][N-1]


print(solution())
