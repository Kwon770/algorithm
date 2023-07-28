# https://www.acmicpc.net/problem/5014
# 5014 스타드링크
# Memory: 41140 KB, Time: 884 ms

"""
문제를 보면 바로 BFS 문제를 알 수 있었다.
단, 강호가 스타트링크가 있는 층에 도착하는 문제이기 때문에, 당연히 조금이라도 움직일 것이라고 생각했지만,
처음부터 목표 층에 있는 케이스도 있기 때문에 주의해야 했다.
"""""


import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 5)
import heapq

top, pos, star, up, down = map(int, readline().split())
visited = [False] * (top + 1)
q = [(0, pos)]

arrived = False
ans = -1
while q:
    count, position = heapq.heappop(q)

    if position == star:
        arrived = True
        ans = count
        break

    if position + up <= top and not visited[position + up]:
        visited[position + up] = True
        heapq.heappush(q, (count + 1, position + up))
    if position - down > 0 and not visited[position - down]:
        visited[position - down] = True
        heapq.heappush(q, (count + 1, position - down))

if arrived:
    print(ans)
else:
    print("use the stairs")