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