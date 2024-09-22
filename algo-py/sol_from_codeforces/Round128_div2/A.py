# https://codeforces.com/contest/1680/problem/A
# A - Minimums and Maximums
# Memory : 9900 KB / Time : 140 ms

import sys; readline = sys.stdin.readline

for _ in range(int(readline())):
    l1, r1, l2, r2 = map(int, readline().split())

    s = l1 + l2
    m = max(l1, l2)

    if s > m and r1 >= m and r2 >= m:
        print(m)
    else:
        print(s)