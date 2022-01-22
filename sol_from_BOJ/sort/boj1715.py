# https://www.acmicpc.net/problem/1715
# 1715 카드 정렬하기
# Memory : 33712 KB, Time : 204 ms

# 그리디식으로 가장 작은 수의 카드 2개를 합쳐가면 최소의 비교 수로 전부 합칠 수 있다.
# 주의할 점은 2개를 합친 카드 또한 정렬된 상태여야 한다는 것이다. (늘 최소인 2개를 선택)
# 1. 합칠 때마다 새로 sort() => O(N^2LogN), 시간 초과
# 2. PriorityQueue 클래스 사용 => 가능하지만, (892ms)
# 3. heapq 클래스 사용 => 더 작은 시간복잡도를 보임 (204ms)

import sys
input=sys.stdin.readline
from heapq import *

n = int(input())
hq = []
for _ in range(n):
    heappush(hq, int(input()))

ans = 0
while len(hq) >= 2:
    comparing = heappop(hq) + heappop(hq)
    ans += comparing
    heappush(hq, comparing)

print(ans)