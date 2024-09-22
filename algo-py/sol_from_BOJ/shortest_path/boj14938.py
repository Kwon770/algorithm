"""
https://www.acmicpc.net/problem/14938
14938 서강그라운드
Memory: 31220 KB, Time: 424 ms

다익스트라로도 풀 수 있지만, 플로이드와샬로 짧게 풀리는 문제.
문제에서도 간단히 떠올릴 수 있었다. 
"""""
INF = 9876543210


n, m, r = map(int, input().split())
items = list(map(int, input().split())) # from 0
distances = [[INF for _ in range(n + 1) ] for _ in range(n + 1)]
for i in range(1, n + 1):
    distances[i][i] = 0;

for _ in range(r):
    a, b, i = map(int, input().split())
    distances[a][b] = i
    distances[b][a] = i

for k in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            distances[a][b] = min(distances[a][b], distances[a][k] + distances[k][b])

ans = 0
for landing in range(1, n + 1):
    score = 0
    for farming in range(1, n + 1):
        if distances[landing][farming] <= m:
            score += items[farming - 1]

    ans = max(ans, score)
print(ans)