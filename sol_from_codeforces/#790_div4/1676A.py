# https://codeforces.com/contest/1676/problem/A
# A Lucky?
# Memory : 4432 KB / Time : 93 ms

import sys; readline = sys.stdin.readline

for _ in range(int(readline())):
    li = list(map(int, input()))
    print(li)
    if li[0] + li[1] + li[2] == li[3] + li[4] + li[5]:
        print("YES")
    else:
        print("NO")