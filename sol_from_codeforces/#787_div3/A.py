# https://codeforces.com/contest/1675/problem/A

import sys; readline = sys.stdin.readline

T = int(readline())
for _ in range(T):
    a, b, c, x, y = map(int, readline().split())

    x -= a
    if x < 0: x = 0
    y -= b
    if y < 0: y = 0

    universal_x = min(x, c)
    x -= universal_x
    c -= universal_x
    y -= c

    if x <= 0 and y <= 0:
        print("YES")
    else:
        print("NO")