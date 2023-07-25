import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
import heapq
EOF = -1

F, S, G, U, D = map(int, readline().split())
dp = [EOF] * (F + 1)

dp[S] = 0
q = [(0, S)]
while q:
    count, now = heapq.heappop(q)
    if now == G:
        break

    for c, n in [(count + 1, now + U), (count + 1, now - D)]:
        if n < 1 or F < n or (dp[n] != -1 and dp[n] <= c):
            continue

        dp[n] = c
        heapq.heappush(q, (c, n))

if dp[G] == EOF:
    print("use the stairs")
else:
    print(dp[G])