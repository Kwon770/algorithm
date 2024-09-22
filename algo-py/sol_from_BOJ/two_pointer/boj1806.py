# https://www.acmicpc.net/problem/1806
# 1806 부분합
# Memory : 42028 KB / Time : 136 ms

# 시간 제한이 0.5초로 상당히 시간복잡도에 엄격한 문제이다.
# 숫자 배열 중 연속된 숫자의 ''부분합''을 구하는 문제라는 점에서 특정 숫자를 탐색하는 것이 아닌 숫자의 범위를 알면 된다는 점에서 투포인터를 이용할 수 있다.
# 부분합이 기준치보다 작은지 큰지에 따라서 left와 right 포인터 중 무엇을 전진시키냐가 달라지는 것이 핵심이다.

# 시간 제한이 엄격한만큼 특정 범위의 부분합을 sum을 통해서 계산해서는 안되고, 포인터가 이동하는 만큼 합계값을 연산해야 한다.

import sys; readline = sys.stdin.readline

def solution():
    ans = 200000
    N, S = map(int, readline().split())
    arr = list(map(int, readline().split()))
    arr.append(0)

    l = 0
    r = 0
    sum_val = arr[0]
    while l <= r and r < N:
        if S <= sum_val:
            ans = min(ans, r - l + 1)
            sum_val -= arr[l]
            l += 1
        else:
            r += 1
            sum_val += arr[r]

    if ans == 200000:
        return 0
    else:
        return ans

print(solution())