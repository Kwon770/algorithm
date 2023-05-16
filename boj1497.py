# itertools 말고 직접 풀어서, 내 스타일 정형화해보기

import sys; readline = sys.stdin.readline
from itertools import product

N, M = map(int, readline().split())
infos = []
for _ in range(N):
    infos.append(list(input().split()))

max_song = -1
min_guitar = N + 1
for selects in product([0,1], repeat=N):
    playables = [False] * M
    for i in range(N):
        if not selects[i]:
            continue

        for j in range(M):
            if infos[i][1][j] == 'N':
                continue

            playables[j] = True

    playable_cnt = playables.count(True)
    if max_song < playable_cnt:
        max_song = playable_cnt
        min_guitar = selects.count(1)
    elif max_song == playable_cnt:
        min_guitar = min(min_guitar, selects.count(1))

if max_song == 0:
    print(-1)
else:
    print(min_guitar)