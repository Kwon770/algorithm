# https://codeforces.com/contest/1675/problem/B

import sys; readline = sys.stdin.readline

T = int(readline())
for _ in range(T):
    n = int(readline())
    li = list(map(int, readline().split()))
    li.append(3000000000)
    li.reverse()

    ans = 0
    for i in range(1, len(li)):
        while li[i - 1] <= li[i]:
            li[i] //= 2
            ans += 1

            if li[i] == 0:
                break

    impossible = False
    for i in range(1, len(li)):
        if li[i - 1] <= li[i]:
            impossible = True

    if impossible:
        print(-1)
    else:
        print(ans)