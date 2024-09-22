# https://www.acmicpc.net/problem/1005
# 1005 ACM Craft
# Memory: 34520 KB, Time: 1408 ms
# Memory: 34324 KB, Time: 888 ms

# 의존관계가 있더라도 결국 그래프 탐색이라고 단순화하였다. 디민, 탐색의 시작점이 정해져있지 않고,
# 여러 개일수도 있기 때문에, 하나 뿐이고 정해진 목적지를 기준으로 탐색하는 방법을 떠올렸다.
# (게임의 건설 의존관계이기 때문에, 싸이클이 없다)

# 일의 병렬이 처리가 가능하지만 의존관계가 있다
# => "해당 일이 시작되기 위해 필요한 일(하위 일)들 중 가장 오래걸리는 것이, 해당 일이 시작되는데 필요한 시간이다" 라고 단순화
#   => 재귀 형태로 하위 일들의 시간 구하고 계산한다
#   ! 서로 겹치는 일들이 많기 때문에 DP 캐싱 처리가 가능하다 !! 1000개의 노드와 10,0000의존관계로 인해 단순히 재귀하면 TLE !!

# 하지만 정석풀이는 "위상정렬" 인듯 하다.
# 위상정렬 : 순서가 정해진 작업을 수행할 때, 이 순서를 결정하는 알고리즘 (DAG, Directed Acyclic Graph, 유향 비순환 그래프 형태여야 함)
# => BFS처럼 큐에 노드를 담아 탐색하고, 탐색 노드마다 "진입점"과 "소요시간"을 계산한다
#   ! 의존관계 때문에 복잡한 노드를 어떻게 큐에 넣을까? !! "진입정"이 0개면, "소요시간" 계산이 끝난 노드, 큐에 추가 !!
# ! 모든 건물이 연결되어 있을리란 보장이 없다 => 큐에 넣을 시작점은 한 개가 아니다 !
# 자세한 풀이: https://blog.itcode.dev/posts/2021/06/01/a1005

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
from collections import deque

"""위상정렬 풀이"""

for T in range(int(input())):
    building_cnt, rule_cnt = map(int, readline().split())
    times = list(map(int, readline().split()))

    rules = [[] for _ in range(1001)]
    prevs = [0] * (1001)
    cost = [0] * (1001)
    for _ in range(rule_cnt):
        x, y = map(int, readline().split())
        rules[x].append(y)
        prevs[y] += 1

    target = int(input())

    q = deque([])
    for i in range(1, building_cnt + 1):
        if prevs[i] == 0:
            q.appendleft(i)
            cost[i] = times[i - 1]

    while q:
        node = q.pop()

        for next in rules[node]:
            prevs[next] -= 1
            cost[next] = max(cost[next], cost[node] + times[next - 1])

            if prevs[next] == 0:
                q.appendleft(next)

    print(cost[target])



"""재귀 + DP 풀이"""
""" 
def recur(node):
    global dp

    t = times[node - 1]
    needed_time = 0
    for needed_node in rules[node]:
        if dp[needed_node] != -1:
            needed_time = max(needed_time, dp[needed_node])
            continue

        node_time = recur(needed_node)
        needed_time = max(needed_time, node_time)
        dp[needed_node] = node_time

    t += needed_time

    return t


for T in range(int(input())):
    building_cnt, rule_cnt = map(int, readline().split())
    times = list(map(int, readline().split()))
    dp = [-1] * (1001)

    rules = [[] for _ in range(1001)]
    for _ in range(rule_cnt):
        x, y = map(int, readline().split())
        rules[y].append(x)

    target = int(input())

    print(recur(target))
"""