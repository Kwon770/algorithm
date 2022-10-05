# https://www.acmicpc.net/problem/1448
# 1448 삼각형 만들기
# Memory : 73656 KB / Time : 780 ms

# 삼각형 변의 성립조건을 활용하는 문제이다.
# 변의 최댓값을 구하는 문제이기 때문에, 정렬 후 선형탐색하면 된다.

import sys; readline = sys.stdin.readline

n = int(input())
nums = []
for _ in range(n):
    nums.append(int(readline()))
nums.sort(reverse=True)

solved = False
for i in range(len(nums) - 3 + 1):
    if nums[i] < nums[i + 1] + nums[i + 2]:
        print(sum(nums[i:i + 3]))
        solved = True
        break

if not solved:
    print(-1)


# n = int(input())
# ans = 0
#
# def calculate(n):
#     global ans
#     d = n
#
#     for dot in [4, 2]:
#         if d >= dot:
#             d -= dot
#             ans += 1
#         else:
#             return ans
#
#     required_dot = [2, 1]
#     while True:
#         for rep in range(2):
#             for dot in required_dot:
#                 if d >= dot:
#                     d -= dot
#                     ans += 1
#                 else:
#                     return ans
#
#         required_dot.append(1)
#
#
# calculate(n)
# print(ans)
# sqrt_n = int(math.sqrt(n))
# for i in range(3, sqrt_n + 1):
#     gap = sqrt_n - i + 1
#     ans += gap*gap
#     print(ans)
#
# print(ans)