# https://www.acmicpc.net/problem/12851
# 12851 숨바꼭질 2
# Memory : 62568 KB / Time : 532 ms

# 여러 이동 방법을 통한 도착 경로 중 최단 거리를 구해야하며 직접 탐색하는 방법 뿐이므로, BFS다.
# (+1) (-1) 이동이 모두 있으므로, visited 관리를 주의해야 한다.
# (*2) 이동 후 (-1) 이동을 통한 도착이 있을 수 있으므로, visited 배열을 넉넉잡아 최대값*2 만큼 마련했다.
# (-1) 이동으로 인해 음수로만 나아가는 이동은 필요가 없으므로, 이 부분을 처리해줘야한다.

import sys; readline = sys.stdin.readline
from collections import deque

def solution():
    N, K = map(int, readline().split())

    fast_time = -1
    fast_way = 0
    found = False
    visited = [False for _ in range(200001)]
    q = deque([(0, N)])
    while q:
        time, now = q.popleft()
        visited[now] = True
        if found and fast_time < time:
            break

        if now == K:
            found = True
            fast_time = time
            fast_way += 1
            continue

        if found:
            continue

        if now + 1 <= 200000 and not visited[now + 1]:
            q.append((time + 1, now + 1))
        if 0 <= now - 1 <= 200000 and not visited[now - 1]:
            q.append((time + 1, now - 1))
        if now * 2 <= 200000 and not visited[now * 2]:
            q.append((time + 1, now * 2))

    print(fast_time)
    print(fast_way)

solution()