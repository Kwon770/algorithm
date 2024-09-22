# https://www.acmicpc.net/problem/17070
# 17070 파이프 옮기기 1
# Memory : 30840 KB / Time : 76 ms

# DP 의 냄새가 옅은데, 파이썬은 그래프 탐색으로 풀 수가 없어서 고생했다.
# 2차원 평면에서 파이프가 이동하며 그 이동 방향이 다양하고 도달하는 모든 경우의 수를 구하라.
# 문제에서 다음 핵심을 보면서 그래프 탐색이라고 생각하고, DFS/BFS를 떠올렸다. 그 중에서도 모든 경우의 수를 구해야하므로,
# 모든 경로를 확인하기위해 BFS로 문제를 설계 했었다. 하지만 이는 TLE인데, 다음을 되짚어봐야했다.

# 우선 BFS로 풀면 모든 경로를 직접 되짚으면서 계산하지만, 이 과정에서 중복된 좌표 탐색이 많다.
# 하지만 파이썬은 느리고 N은 최대 16, 시간제한은 1초이므로, 넉넉한 문제가 아니다.
# 그래프 탐색을 해야하는 경우, BFS여야만 하는 것이 아니라면 DFS를 사용하는 것이 낫다.
# 단, 이 문제는 DFS도 pypy3가 아닌 이상, TLE다.

# 문제에서 파이프 이동 방향이 단서인데, 우하단으로만 이동한다. 즉, 파이프의 경로 갯수를 한 번 계산하더라도, 이 값은 변하지 않을 것이다. 따라서 DP 로 푸는 것이 옳다.
# ! 최적화의 여지가 있고 문제의 조건이 여유롭지 않기 때문에 최대한 최적화를 해보자라는 흐름으로 DP를 떠올리는 흐름을 가져보자 !

# ! 2차원과 좌표기준 문제이다보니, 좌표기준 탐색 풀이를 풀었는데 (./boj17070_try.py) 깔끔하지도 않고 최선이 아니다.
# 파이프의 범위가 그렇게 넓지않고 그래프보다 DP의 관점에서 본다면 이와같은 풀이가 깔끔하고 적당하다.

# ! 파이썬에서 배열 범위 밖 접근을 조심하자. 오류가 나지않고 이상한 값이 나왔다.
# ( for c in range(1, N) , if r > 0 )
# ( 어차피 우하단 이동이므로, 시작지점보다 뒤쪽은 고려안해도 된다, r = 0 에서 하강, 우하강 이동을 고려할 필요가 없다)

import sys; readline = sys.stdin.readline

N = int(readline())
home = [list(map(int, readline().split())) for _ in range(N)]
cache = [[[0,0,0] for _ in range(N)] for _ in range(N)]

cache[0][1][0] = 1
for r in range(N):
    for c in range(1, N):
        if home[r][c] == 1:
            continue

        cache[r][c][0] += cache[r][c - 1][0] + cache[r][c - 1][2]
        if r > 0:
            cache[r][c][1] += cache[r - 1][c][1] + cache[r - 1][c][2]

            if home[r - 1][c] == 0 and home[r][c - 1] == 0:
                cache[r][c][2] += sum(cache[r - 1][c - 1])

for r in cache:
    print(r)
print(sum(cache[N - 1][N - 1]))