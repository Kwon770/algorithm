
# 브루트포스 vs 그리디? 그리디면 안되는 이유가?
# 완탐이 될거같은 범위면 보통 그냥 완탐
# 보통은 범위가 말도안되게 크면, 그리디이기도 함

# 시간복잡도 ?

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N = map(int, readline().split())
arr = [0] * (1001)
left  = 1001
right = 0
top_h = 0
top_l = 0
for n in range(N):
    L, H = map(int, readline().split())
    if L < left:
        left = L
    if L > right:
        right = L
    if top_h < H:
        top_h = H
        top_l = L

ans = 0
prev = arr[left]
for i in range(left + 1, top_l + 1):
    if prev < arr[i]:
        ans +=