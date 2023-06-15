# https://www.acmicpc.net/problem/3343
# 3343 장미
# Memory: 33376 KB, Time: 104 ms

# 실패
# 풀이 : https://sckwon770.notion.site/Page-1-5025a108f55f43c1b424fb9747e93036?pvs=4

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
