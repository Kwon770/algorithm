# https://www.acmicpc.net/problem/10775
# 10775 공항
# Memory: 35108 KB, Time: 144 ms, python3

"""

"""""

import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)


N, K = map(int, readline().split())
arr = []
for i in list(map(int, readline().split())):
    arr.append((str(bin(i)).count('1'), i))

arr.sort(reverse = True)
print(arr[K - 1][1])