import sys

sys.setrecursionlimit(10 ** 6)

NONE = 'none'
DONUT = 'donut'
EIGHT = 'eight'

visited = [False for _ in range(1000001)]
near_edges = [[] for _ in range(1000001)]


def dfs(node, predict):
    global visited, near_edges
    if visited[node]:
        if predict == NONE:
            return DONUT
        else:
            return EIGHT

    visited[node] = True

    if len(near_edges[node]) == 2:
        predict = EIGHT
    for edge in near_edges[node]:
        predict = dfs(edge, predict)

    return predict


def solution(edges):
    global visited, near_edges
    donut_count = 0
    stick_count = 0
    eight_count = 0
    e = len(edges)

    node_level = [0] * 1000001
    for a, b in edges:
        near_edges[a].append(b)
        node_level[a] += 1
        node_level[b] -= 1

    external_dot = 0
    for i in range(1, 1000001):
        if node_level[i] >= 2:
            external_dot = i
            break
    visited[external_dot] = True

    for node in near_edges[external_dot]:
        if visited[node]:
            continue

        graph = dfs(node, NONE)
        if graph == NONE:
            stick_count += 1
        elif graph == DONUT:
            donut_count += 1
        elif graph == EIGHT:
            eight_count += 1

    return [external_dot, donut_count, stick_count, eight_count]