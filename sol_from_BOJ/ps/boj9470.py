# https://www.acmicpc.net/problem/9470
# 9470 Strahler 순서
# Memory : 32484 KB / Time : 84 ms

# 그래프와 위상정렬 태그지만, 캐싱과 BFS로 품

# Strahler 순서를 알기위해선 해당 노드에 연결된 노드의 Strahler 순서를 알아야 한다.
# 단, 사이클이 없고 단방향으로 노드가 진행되는 것으로 보인다 (조건이 명시되지는 않았으나, 문제의 흐름이 그럼)

# 따라서 두 가지가 선행되어야 하는데,
# 1. 각 노드에 어떤 노드들이 연결되었는지 알아내기
# 1-1. 각 노드가 어디로 연결되었는지는 간선으로 알 수 있으므로, 어떤 노드가 연결되었는지는 사전에 간선을 순회하면서 계산

# 2. 연결된 노드들의 Strahler 순서가 뭔지?
# 2-1. 근본 루트부터 시작하여 BFS 메커니즘으로 Strahler 순서 계산을 한다.
# 2-2. 단, 최적화를 위해 visited[]를 통하여 한 번만 방문하게 해선 안된다. 노드가 꼭 차례대로 연결된다는 보장이 없으므로,
#      근본 노드가 최하단 노드로 연결되어 BFS 순서가 꼬일경우, 계산이 잘못된다. 여러번 방문해서 매번 계산하게 한다.


import sys; readline = sys.stdin.readline
from collections import deque

for tc in range(1, int(readline()) + 1):
    K, M, P = map(int, readline().split())
    edges = [[False] * (M + 1) for _ in range(M + 1)]
    for _ in range(P):
        a, b = map(int, readline().split())
        edges[a][b] = True

    flow = [[] for _ in range(M + 1)]
    for i in range(1, M + 1):
        for j in range(1, M + 1):
            if not edges[i][j]: continue

            flow[j].append(i)

    ans = 1
    seq = [0] * (M + 1)
    dq = deque([])
    for i in range(1, M + 1):
        if len(flow[i]) == 0:
            dq.append(i)

    while dq:
        node = dq.popleft()

        maxUpperSeq = 0
        maxUpperSeqCnt = 0
        for upper in flow[node]:
            if maxUpperSeq < seq[upper]:
                maxUpperSeq = seq[upper]
                maxUpperSeqCnt = 1
            elif maxUpperSeq == seq[upper]:
                maxUpperSeqCnt += 1

        if maxUpperSeqCnt == 0:
            maxUpperSeq = 1
        elif maxUpperSeqCnt > 1:
            maxUpperSeq += 1

        seq[node] = maxUpperSeq
        ans = max(ans, maxUpperSeq)

        for j in range(1, M + 1):
            if edges[node][j]:
                dq.append(j)

    print(tc, ans)