import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N = int(input())
arr = [0] * (1001)
left  = 1001
right = 0
top_h = 0
top_l = 0
for n in range(N):
    L, H = map(int, readline().split())
    arr[L] = H
    if L < left:
        left = L
    if L > right:
        right = L
    if top_h < H:
        top_h = H
        top_l = L

ans = 0
prev = left
for i in range(left, top_l + 1):
    if i == top_l:
        ans += (i - prev) * arr[prev]

    elif arr[prev] < arr[i]:
        ans += (i - prev) * arr[prev]
        prev = i

prev = right + 1
for i in range(right + 1, top_l - 1, -1):
    # print(i, prev, arr[i - 1], arr[prev - 1])
    if i == top_l:
        ans += (prev - i) * arr[i]

    elif arr[prev - 1] < arr[i - 1]:
        ans += (prev - i) * arr[prev - 1]
        # print((prev - i) * arr[prev - 1])
        prev = i

print(ans)
