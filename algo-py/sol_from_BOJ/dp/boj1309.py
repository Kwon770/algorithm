# https://www.acmicpc.net/problem/1309
# 1390 동물원

# 전형적인 DP 느낌도 나고, 풀이도 DP인 문제다.
# 다만, 점화식을 제대로 떠올리지 못해서 못풀었다.

import sys; readline = sys.stdin.readline

def solution():
    N = int(input())
    memo = [[1] * 3 for _ in range(N+1)]
    for i in range(2, N+1):
        memo[i][0] = (memo[i - 1][1] + memo[i - 1][2]) % 9901
        memo[i][1] = (memo[i - 1][0] + memo[i - 1][2]) % 9901
        memo[i][2] = (memo[i - 1][0] + memo[i - 1][1] + memo[i - 1][2]) % 9901

    return sum(memo[N]) % 9901


print(solution())