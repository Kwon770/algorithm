# https://www.acmicpc.net/problem/18111
# 18111 마인크래프트
# Memory: 31256 KB, Time: 228 ms, python3
# Memory: 117665 KB, Time: 816 ms, pypy3


"""
풀이: https://www.notion.so/sckwon770/18111-Python3-pypy3-5d816cd7c52e430080d76cc62c45eaea?pvs=4
"""""

import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

N, M, B = map(int, readline().split())
ground = [0] * (257)

min_h = 257
max_h = -1
for n in range(N):
    a = list(map(int, readline().split()))
    for b in a:
        ground[b] += 1
        min_h = min(min_h, b)
        max_h = max(max_h, b)

min_time = sys.maxsize
ans_h = 0
for h in range(min_h, max_h + 1):

    use = 0
    take = 0
    for k in range(min_h, max_h + 1):
        if k < h:
            use += (h - k) * ground[k]
        else:
            take += (k - h) * ground[k]


    if use > take + B:
        continue
    else:
        time = take * 2 + use
        if min_time >= time:
            min_time = time
            ans_h = h
print(min_time, ans_h)


import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

N, M, B = map(int, readline().split())
grounds = []
max_h = -1
min_h = 257
for n in range(N):
    grounds.append(list(map(int, readline().split())))

    for g in grounds[-1]:
        max_h = max(max_h, g)
        min_h = min(min_h, g)

min_time = sys.maxsize
ans_h = 0
for h in range(min_h, max_h + 1):

    use = 0
    take = 0
    for i in range(N):
        for j in range(M):
            if h < grounds[i][j]:
                take += grounds[i][j] - h
            else:
                use += h - grounds[i][j]

    if use > take + B:
        continue
    else:
        time = take * 2 + use
        if min_time >= time:
            min_time = time
            ans_h = h
print(min_time, ans_h)