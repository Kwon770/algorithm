# 0 0 0 0
# 0 0 2 0
# 0 0 0 1
# time, map, blocks
# 1 + 25,0000 + 1
# 1024mb 1.008kb
# BFS 동시 탐색 가능 케이스가 1000개 정도? 불안하다. 터질거같음

# 현상태 => 최적상태를 탐색하는 방식이 모호함
# 차라리 높이 h를 만드는데 필요한 시간을 구하자? 어차피 블럭의 최소와 최대 사이일꺼니까?
# 256*500*500 = 6400만

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N, M, B = map(int, readline().split())
grounds = []
max_h = -1
min_h = 257
for n in range(N):
    grounds.append(list(map(int, readline().split())))

    for g in grounds[-1]:
        if max_h < g:
            max_h = g
        if min_h > g:
            min_h = g

min_time = sys.maxsize
ans_h = 0
for h in range(min_h, max_h + 1):

    time = 0
    b = B
    for i in range(N):
        for j in range(M):
            if h < grounds[i][j]:
                time += (grounds[i][j] - h) * 2
                b += (grounds[i][j] - h)
            elif h > grounds[i][j]:
                time += (h - grounds[i][j]) * 1
                b -= (h - grounds[i][j])

    if b < 0:
        continue
    else:
        if min_time > time:
            min_time = time
            ans_h = h
print(min_time, ans_h)