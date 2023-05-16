import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N, W = map(int, readline().split())
tree = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    a, b = map(int, readline().split())
    tree[a].append(b)
    tree[b].append(a)

visited = [False] * (N + 1)
leaf = []
def recur(node):
    global visited, leaf

    is_last = True

    for n in tree[node]:
        if not visited[n]:
            is_last = False
            visited[n] = True
            recur(n)

    if is_last:
        leaf.append(node)


visited[1] = True
recur(1)
print(float(W) / len(leaf))