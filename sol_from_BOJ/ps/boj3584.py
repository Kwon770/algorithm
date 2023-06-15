# https://www.acmicpc.net/problem/3584
# 3584 가장 가까운 공통 조상
# Memory: 31256 kb, Time: 72 ms

# 서로 다룬 두 노드들의 공통 조상을 알기위해서는 각자의 조상들을 먼저 뽑을 필요가 있었다.
# rooted tree이므로, 부모가 없는 노드(루트)까지 부모를 향해 올라가고, 그 흔적을 남긴다.

# 이 과정에서 최적화가 갈렸는데
# [기존풀이] a와 b의 조상들을 배열로 남기고, 가장 먼저 겹치기 시작하는 노드를 찾았다
# [최적화] 그럴 필요없이, a가 조상을 찾기위해 탐색하는 경로를 visited하고, b가 조상을 탐색하다가 방문한 노드일 경우 => 겹치기 시작하는 조상
# (바로 떠올리기 힘든 논리였지만, 헷갈리는 로직없이 깔끔하다)

# ! 주의할점은 a 혹은 b 본인이 LCA가 될 수도 있다는 점이다. 이를 고려해서 조건 처리를 잘 해야한다. !

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)


for T in range(int(readline())):
    parents = [-1] * (10001)
    visited = [False] * (10001)
    N = int(readline())

    for _ in range(N - 1):
        parent, child = map(int, readline().split())
        parents[child] = parent

    a, b = map(int, readline().split())
    visited[a] = True
    while parents[a] != -1:
        a = parents[a]
        visited[a] = True

    while not visited[b] and parents[b] != -1:
        b = parents[b]

    print(b)


""" 기존 풀이

# 본인포함 모든 조상을 반환함
def get_ancestors(start):
    global parents

    ancestors = [start]
    while parents[start] != -1:
        ancestors.append(parents[start])
        start = parents[start]

    return ancestors


parents = []
for _ in range(int(readline())):
    N = int(readline())
    parents = [-1] * (10001)
    for _ in range(N - 1):
        parent, child = map(int, readline().split())
        parents[child] = parent

    a, b = map(int, readline().split())
    a_ancestors = get_ancestors(a)
    b_ancestors = get_ancestors(b)

    # a의 조상부터 차례대로 b의 조상과 겹치는지 확인, 먼저 확인한 조상이 가장 가까움
    nearest_ancestor = -1
    for a_ancestor in a_ancestors:
        if a_ancestor in b_ancestors:
            nearest_ancestor = a_ancestor
            break

    print(nearest_ancestor)
"""