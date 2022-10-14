# https://codeforces.com/contest/1742/problem/B
# B. Increasing
# Memory : 1600 KB / Time : 46 ms

# 정렬 시간보다도 단축하기 위해, Bool형 배열을 활용할려고 했지만 10^9 + 1길이의 배열이 많은 부하를 가했다.

import sys; readline = sys.stdin.readline

t = int(readline())
for _ in range(t):
    n = int(readline())
    arr = list(map(int, readline().split()))
    arr.sort()

    broken = False
    for i in range(1, n):
        if arr[i - 1] == arr[i]:
            broken = True
            break

    if broken:
        print("NO")
    else:
        print("YES")