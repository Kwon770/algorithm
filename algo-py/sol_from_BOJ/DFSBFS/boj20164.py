# https://www.acmicpc.net/problem/20164
# 20165 홀수 홀릭 호석
# Memory: 31256 KB, Time: 44 ms

# 모든 과정에서 값을 계산하고, 최댓값 최소값을 출력해야한다 => 특정한 규칙이 있거나 점화식이 없을 것이라는 냄새가 남
# N이 최대 10^9로서 브루트푸스 DFS하기에 값이 애매하지만, 다른 방도가 없어 보인다.

# 결과적으로 아무 장치없이 브루트포스 DFS를 해도 풀린다.
# 하지만 dp의 여지가 보이므로, 시도해보았다. 숫자값마다의 캐싱을 해야하지만 N이 크므로, 배열이 아닌 !dict로 한 것에 주목!

# ! DFS가 깊어질 것으로 보이므로, sys.setrecurssionlimit() 필수
# ! return a, b => 또한 튜플반환, 출력할 때 조심.


import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

dp = dict()

# 홀수 갯수 구하기
def get_odd_cnt(num):
    count = 0
    for n in num:
        if int(n) % 2 != 0:
            count += 1

    return count

def dfs(num):
    global N, dp

    length = len(num)
    if length == 1:
        cnt = 0
        if int(num[0]) % 2 == 1: cnt += 1
        return (cnt, cnt)

    if num in dp:
        return dp[num]

    cnt = get_odd_cnt(num)
    if length == 2:
        new_num = int(num[0]) + int(num[1])
        max_val, min_val = dfs(str(new_num))

        dp[num] = (max_val + cnt, min_val + cnt)
        return dp[num]

    max_total = -1
    min_total = sys.maxsize
    if length >= 3:
        for left in range(1, length - 1):
            for right in range(left + 1, length):
                l, m, r = int(num[:left]), int(num[left:right]), int(num[right:])
                new_num = l + m + r
                max_val, min_val = dfs(str(new_num))

                max_total = max(max_total, max_val)
                min_total = min(min_total, min_val)

        dp[num] = (max_total + cnt, min_total + cnt)
        return dp[num]


N = input()
max_ans, min_ans = dfs(N)
print(min_ans, max_ans)

# import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)
#
# # 홀수 갯수 구하기
# def get_odd_cnt(num):
#     count = 0
#     for n in num:
#         if int(n) % 2 != 0:
#             count += 1
#
#     return count
#
# def dfs(num, count):
#     global N, max_val, min_val
#     # 로직이라 ㅇ상관없이 늘 홀수 갯수 계산
#     count += get_odd_cnt(num)
#
#     length = len(num)
#     # 기저 조건
#     if length == 1:
#         max_val = max(max_val, count)
#         min_val = min(min_val, count)
#         return
#
#     elif length == 2:
#         new_num = int(num[0]) + int(num[1])
#         dfs(str(new_num), count)
#
#     elif length >= 3:
#         # 가능한 모든 경우 재귀 (중간 범위의 숫자의 left, right로 자름, slice index 기준)
#         for left in range(1, length - 1):
#             for right in range(left + 1, length):
#                 l, m, r = int(num[:left]), int(num[left:right]), int(num[right:])
#                 new_num = l + m + r
#                 dfs(str(new_num), count)
#
#
# N = input()
# max_val = -1
# min_val = sys.maxsize
# dfs(N, 0)
# print(min_val, max_val)