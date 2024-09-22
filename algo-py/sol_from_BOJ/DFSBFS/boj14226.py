# https://www.acmicpc.net/problem/14226
# 14226 이모티콘
# Memory : 57380 KB / Time : 300 ms

import sys; readline = sys.stdin.readline
from collections import deque

def solution():
    S = int(readline())

    visited = [False for _ in range(10000)]
    q = deque([(0, 1, 0)])
    while q:
        time, cnt, clipboard = q.popleft()
        visited[cnt] = True

        if clipboard != 0 and cnt + clipboard == S:
            return time + 1
        elif cnt + clipboard < 10000 and not visited[cnt + clipboard]:
            q.append((time + 1, cnt + clipboard, clipboard))

        if clipboard != cnt:
            q.append((time + 1, cnt, cnt))

        if cnt - 1 == S:
            return time + 1
        elif 2 <= cnt - 1 and not visited[cnt - 1]:
            q.append((time + 1, cnt - 1, clipboard))

print(solution())