# https://programmers.co.kr/learn/courses/30/lessons/60061
# 2020 KAKAO BLUND RECRUITMENT, 기둥과 보 설치

from collections import deque
import heapq

INF = int(1e9)

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

    q = [(start, 0)]
    while q:
        now, dist = heapq.heappop()
        if distance[now] < dist:
            continue

        for node in graph[now]:
            cost = distance[now] + node[1]
            if distance[node[0]] > cost:
                distance[node[0]] = cost
                heapq.heappush(q, (node[0], cost))


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
                    return True
    return False

import sys; import sys; sys.setrecursionlimit(10 ** 6); input = sys.stdin.readline().rstrip

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]


def rotateR(idx):
    idx += 1
    if idx == 4:
        idx = 0
    return idx


def rotateL(idx):
    idx -= 1
    if idx == -1:
        idx = 3
    return idx


def get_cycle(grid, i, j, rotation):
    currentCycle = []
    length = 0
    while True:
        if grid[i][j] == "R":
            rotation = rotateR(rotation)
        elif grid[i][j] == "L":
            rotation = rotateL(rotation)

        ni = i + dr[rotation]
        nj = j + dc[rotation]
        now = [(i, j), (ni, nj)]
        if now in currentCycle:
            return [length, currentCycle]

        if ni >= r:
            currentCycle.append(now)
            now = [(-1, nj), (0, nj)]
            i = 0
            j = nj
        elif ni < 0:
            currentCycle.append(now)
            now = [(r, nj), (r - 1, nj)]
            i = r - 1
            j = nj

        elif nj >= c:
            currentCycle.append(now)
            now = [(ni, -1), (ni, 0)]
            i = ni
            j = 0
        elif nj < 0:
            currentCycle.append(now)
            now = [(ni, c), (ni, c - 1)]
            i = ni
            j = c - 1
        else:
            i = ni
            j = nj

        currentCycle.append(now)
        length += 1


def solution(grid):
    global answer, cycle, r, c
    answer = []
    cycles = []
    r = len(grid)
    c = len(grid[0])
    for i in range(r):
        for j in range(c):
            for rotation in range(4):
                length, new_cycle = get_cycle(grid, i, j, rotation)
                new_cycle.sort()

                duplicated = False
                for cycle in cycles:
                    if new_cycle[0] == cycle[0]:
                        duplicated = True
                        break
                if not duplicated:
                    answer.append(length)
                    cycles.append(new_cycle)

    answer.sort()
    return answer

# print('10'.replace('0', ''))
print(solution(["SL","LR"]))