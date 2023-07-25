

# 100^3 = 100,0000
# 만약 범위가 크다면?

# DP를 해야겠는데?

# itertools 직접 짜는법

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
from itertools import combinations

fr = [0, -1, 0, 1, 0]
fc = [0, 0, 1, 0, -1]

def to_axis(a):
    return (a // N), (a % N)

N = int(input())
pots = []
for i in range(N):
    pots.append(list(map(int, readline().split())))

ans = sys.maxsize
for pos in combinations([i for i in range(0, N*N)], 3):
    price = 0
    visited = [[False for c in range(N)] for r in range(N)]
    for p in pos:
        r, c = to_axis(p)

        visitable = True
        for f in range(5):
            nr = r + fr[f]
            nc = c + fc[f]

            if nr < 0 or nc < 0 or N <= nr or N <= nc or visited[nr][nc]:
                visitable = False
                break
        # print(r, c, visitable)
        if not visitable:
            break

        for f in range(5):
            nr = r + fr[f]
            nc = c + fc[f]

            visited[nr][nc] = True
            price += pots[nr][nc]

    if not visitable:
        continue

    ans = min(ans, price)
print(ans)