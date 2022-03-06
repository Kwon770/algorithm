# https://www.acmicpc.net/problem/2163
# 2163 초콜릿 자르기

# DP로도 풀 수 있지만, 문제의 진의를 알아채면 단순한 계산식으로 풀 수 있다.

import sys; readline = sys.stdin.readline

def solution():
    N, M = map(int, input().split())
    return N * M + 1

print(solution_dp())