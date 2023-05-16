# DP가 필요없는 버전
# 이건 트리 DP
# https://www.acmicpc.net/problem/11438

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

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
