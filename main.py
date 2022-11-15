# https://www.acmicpc.net/problem/14215
# 14215 세 막대
# Memory: 30840kb / Time: 68ms

# https://way-code.tistory.com/entry/%EB%B0%B1%EC%A4%80-14215%EB%B2%88-%EC%84%B8-%EB%A7%89%EB%8C%80-%ED%8C%8C%EC%9D%B4%EC%8D%AC

import sys; readline = sys.stdin.readline

lines = list(map(int, readline().split()))
lines.sort()
cond = lines[0] + lines[1]
if cond <= lines[2]:
    print(lines[0] + lines[1] + cond - 1)
else:
    print(sum(lines))


# https://www.acmicpc.net/problem/2531
# import sys; readline = sys.stdin.readline
#
# n, d, k, c = map(int, readline().split())
# sushi = [int(readline()) for _ in range(n)]
# sushi += sushi[:k]
#
# ans = -1
# for i in range(n):
#     kind = set(sushi[i:i+k])
#     comb = len(kind)
#     if c not in kind:
#         comb += 1
#
#     ans = max(ans, comb)
# print(ans)

# https://www.acmicpc.net/problem/2981
# import sys; readline = sys.stdin.readline
# from math import gcd, sqrt
#
# n = int(readline())
# nums = [int(readline()) for _ in range(n)]
# nums.sort(reverse=True)
#
# subs = []
# for i in range(n - 1):
#     subs.append(nums[i] - nums[i + 1])
#
# g = subs[0]
# for i in range(1, len(subs)):
#     g = gcd(g, subs[i])
#
# ans = [g]
# for i in range(2, int(sqrt(g)) + 1):
#     if g % i != 0:
#         continue
#
#     ans.append(i)
#     ans.append(g // i)
# ans = sorted(list(set(ans)))
# print(*ans)