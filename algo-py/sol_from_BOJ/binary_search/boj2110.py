# https://www.acmicpc.net/problem/2110
# 2110 공유기 설치
# Memory : 40656 KB, Time : 308 ms

# 이분 탐색을 적용하지 않으면 시간 초과가 나는 문제
# 최적화 포인트는
# 1. 가능한 거리를 확인할 때 high 를 최대값을 설정하는 것이 아니라, 실질적으로 가능한 값의 최대로 설정 (집 간의 총 거리 // (공유기 수-1) + 1)
# 2. 해당 거리를 둔 설치가 가능한지 확인할 때, 단순히 모든 집을 돌면서 확인하는게 아니라 여기서도 이분 탐색을 활용

import bisect
import sys
input=sys.stdin.readline

def isPossibleCase(houses, distance):
    global n, wifi

    prev = houses[0]
    for _ in range(wifi - 1):
        idx = bisect.bisect_left(houses, prev + distance)
        if idx >= n:
            return False

        prev = houses[idx]

    return True


n, wifi = map(int, input().split())
houses = [int(input()) for _ in range(n)]
houses.sort()

ans = 0
low = 1
high = (houses[-1] - houses[0]) // (wifi-1) + 1
while low <= high:
    mid = (high + low) // 2
    if isPossibleCase(houses, mid):
        low = mid + 1
        ans = max(ans, mid)
    else:
        high = mid - 1

print(ans)