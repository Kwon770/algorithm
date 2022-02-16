# DP - Q31 금광 (P375)
# 문제 링크 : https://sckwon770.notion.site/Q31-15f35fe401824739b7a971df3b4e4e44

# DP 전형적인 유형 : 캐싱이 없으면 고려해야할 경우의 수가 너무 많은 문제
# 캐싱을 통해 O(N)을 만들려하지말고, "현 단계의 경우의 수가 다음 단계의 경우의 수에 영향을 미치지 않을 저도로만 만들면 됨"
# 즉, 매번 현 단계에서 고려해야하는 모든 경우의 수를 확인하여 최적값을 캐싱하면 된다.

# 현 단계가 다음 단계에 영향을 미치는 O(N^M)
#       1 <
# 1 <
#       2 <
#
#       1 <
# 2 <
#       2 <

import sys
input = sys.stdin.readline

drs = [-1, 0, 1]

def solution():
    for TC in range(int(input())):
        n, m = map(int, input().split())
        arr = list(map(int, input().split()))

        memo = []
        idx = 0
        for r in range(n):
            memo.append(arr[idx:idx+m])
            idx += m

        for c in range(1, m):
            for r in range(n):
                maxPr = -1
                for dr in drs:
                    pr = r + dr
                    if pr == -1 or pr == n:
                        continue

                    maxPr = max(maxPr, memo[pr][c-1])
                memo[r][c] += maxPr

        result = -1
        for r in range(n):
            result = max(result, memo[r][-1])
        print(result)

print(solution())