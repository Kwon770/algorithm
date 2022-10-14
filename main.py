# https://www.acmicpc.net/problem/24025
# 24025 돌의 정렬 줄세우기
# Memory : 38624 KB / Time : 124 ms

# 문제의 핵심은 어느정도 깨달았지만, PS하기 위한 이해와 실제 PS로 옮기지는 못했다.


# import sys; readline = sys.stdin.readline
# from itertools import combinations
# from math import gcd
#
#
# t = int(readline())
# for _ in range(t):
#     n = int(readline())
#     arr = list(map(int, readline().split()))
#     index = [-1] * (200001)
#     for i in range(n - 1, -1 ,-1):
#         if index[arr[i]] == -1:
#             index[arr[i]] = i + 1
#
#     ans = -1
#     for comb in combinations(arr, 2):
#         if gcd(comb[0], comb[1]) == 1:
#             ans = max(ans, index[comb[0]] + index[comb[1]])
#
#     for ele in arr:
#         if gcd(ele, ele) == 1:
#             ans = max(ans, index[ele] + index[ele])
#
#     print(ans)


# import sys; readline = sys.stdin.readline
# from math import gcd
#
#
# t = int(readline())
# for _ in range(t):
#     n = int(readline())
#     arr = list(map(int, readline().split()))
#
#     ans = -1
#     for i in range(n - 1, -1, -1):
#         for j in range(i, -1, -1):
#             if gcd(arr[i], arr[j]) == 1:
#                 ans = max(ans, i + j + 2)
#                 break
#
#     print(ans)

