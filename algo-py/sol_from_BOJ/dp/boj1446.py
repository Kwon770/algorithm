# https://www.acmicpc.net/problem/1446
# 1446 지름길
# Memory : 32276 KB / Time : 48 ms

# 다익스트라 테그가 붙어있지만, dp의 냄새가 강한 문제다.
# 전형적으로 가능한 경우의 수를 전부 확인은 해야하지만, 캐싱하면서 순회를 함으로서 복잡도를 줄이는 문제다.

# 일반 통행과 고속도로는 역주행이 불가능하다는 점이 힌트다.

import sys; readline = sys.stdin.readline

dist = [i for i in range(10001)]
shortcuts = [[] for _ in range(10001)]

N, D = map(int, readline().split())
for _ in range(N):
    s, e, d = map(int, readline().split())
    shortcuts[s].append((e, d))

for i in range(D):
    dist[i + 1] = min(dist[i + 1], dist[i] + 1)
    for shortcut in shortcuts[i]:
        e, d = shortcut

        dist[e] = min(dist[e], dist[i] + d)

print(dist[D])