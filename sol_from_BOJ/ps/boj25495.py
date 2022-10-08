# https://www.acmicpc.net/problem/25495
# 25495 에어팟
# Memory : 30840 KB / Time : 68 ms

# 주어진 순서의 매 단계의 값은 이전 단계에 의존적이기 때문에, O(N) 선형탐색으로 계산할 수 있고
# N <= 1000 으로 큰 범위가 아니므로, 간단하계 선형탐색으로 해결했다.

import sys; readline = sys.stdin.readline

n = int(readline())
seq = list(map(int, readline().split()))

prev_phone = -1
prev_usage = 0
usage = 0
for phone in seq:
    if prev_phone == phone:
        prev_usage *= 2
    else:
        prev_usage = 2

    usage += prev_usage
    prev_phone = phone
    if 100 <= usage:
        prev_phone = -1
        usage = 0

print(usage)