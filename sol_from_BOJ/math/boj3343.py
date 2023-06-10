# https://www.acmicpc.net/problem/3343
# 3343 장미
# Memory: 33376 KB, Time: 104 ms

# 실패
# 풀이 : https://sckwon770.notion.site/Page-1-5025a108f55f43c1b424fb9747e93036?pvs=4

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
import math

# N <= 1000,0000,0000,0000
# A, B, C, D <= 10,0000
N, A, B, C, D = map(int, readline().split())
price = 0

# A 가 가성비 좋은, C 가 가성비 나쁜
if B/A > D/C:
    A, C = C, A
    B, D = D, B

ans = sys.maxsize
lcm = math.lcm(A, C)
for c_buy in range(lcm//C):
    a_buy = math.ceil((N - (C * c_buy)) / A)

    is_over = False
    if a_buy < 0:
        a_buy = 0
        is_over = True

    ans = min(ans, a_buy*B + c_buy*D)
    if is_over: break
print(ans)