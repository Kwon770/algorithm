# Greedy - Q5 볼링공 고르기 (P315)

# 고민없이 풀면 같은 무게끼리의 조합을 제외한 볼링공 번호 조합의 갯수를 구하는 식으로 문제를 풀게 됨.
# 하지만 이 방식은 모든 조합을 직접 구하는 것이므로, 비효율적임.

# 문제는 갯수만 요구하므로, [조합의 성질 + 같은 무게의 공끼리는 제외]인 점을 이용해서
# (현재 무게의 갯수 * 현재 무게보다 무거운 공의 갯수) 식을 이용해서 조합의 갯수만을 계산할 수 있다.

import sys
input = sys.stdin.readline

def solution():
    n, m = map(int, input().split())
    weights = list(map(int, input().split()))
    counts = [0] * 11

    for w in weights:
        counts[w] += 1

    ans = 0
    for i in range(1, m+1):
        n -= counts[i]
        ans += counts[i] * n

    return ans

# def not_effective_solution():
#     n, m = map(int, input().split())
#     weights = list(map(int, input().split()))
#     balls = [(i+1, weights[i]) for i in range(n)]
#
#     combination = []
#     for i in range(n):
#         for j in range(i+1, n):
#             if balls[i][1] == balls[j][1]:
#                 continue
#
#             combination.append((balls[i][0], balls[i][0]))
#
#     return len(combination)

print(solution())