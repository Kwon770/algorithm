# https://www.acmicpc.net/problem/8980
# 8980 택배

# 문제의 큰 유형만 보면 DP 문제로 보이지만, 그리디로 푸는 독특한 문제
# 따라서 테케로 솔루션을 추론할 때, DP적인 관점으로 생각하면 미궁에 빠지기 쉽다.
# """그리디로 풀 수 있는 핵심은 택배의 양을 필요한 만큼만 배송할 수 있다는 것이다."""
# DP적인 방법으로 택배를 옮길 수도 있지만, 그리디/택배 분할 방법으로도 최적의 답을 구할 수 있다.

# 그리디를 위한 정렬 기준은 자칫 (출발 도시 오름차순, 도착도시 오름차순, 택배양 내림차순) 순으로 정렬할 수 있는데,
# 이는 (1, N) 과 같이 소요 거리가 큰 택배를 먼저 배송하게 되는 반례가 있다. 즉, 소요거리로 정렬하지 못하는 것이다.
# (도착도시 오름차순, 출발도시 내림차순, 택배양 내림차순) 으로 정렬할 경우, 소유거리가 적은 택배 먼저 배송하게 된다.

import sys; sys.setrecursionlimit(10 ** 6); input = sys.stdin.readline

def solution():
    N, C = map(int, input().split())
    M = int(input())
    deliverys = []
    for _ in range(M):
        f, t, v = map(int, input().split())
        deliverys.append((f, t, v))
    deliverys.sort(key=lambda x:(x[1],-x[0],-x[2]))

    answer = 0
    weights = [0] * (N+1)
    for delivery in deliverys:
        f, t, v = delivery
        max_weight = max(weights[f:t])
        if max_weight == C:
            continue

        possible_weight = C - max_weight
        delivery_weight = min(v, possible_weight)
        for i in range(f, t):
            weights[i] += delivery_weight
        answer += delivery_weight

    return answer

print(solution())