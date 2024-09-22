# 회전조건이 회전하고나서가 아니라, 회전이전이라는게, 인지와 너무 달라서 마지막까지 헤맸음
import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
from collections import deque

def rotate(gear, d):
    if d == 1:
        gear.appendleft(gear[-1])
        gear.pop()
    elif d == -1:
        gear.append(gear[0])
        gear.popleft()

T = int(input())
gears = []
for t in range(T):
    gears.append(deque(readline().split()[0]))

K = int(input())
for k in range(K):
    n, d = map(int, readline().split())
    n -= 1

    rotated_gears = [(n, d)]
    # Left
    left_d = d
    for i in range(n - 1, -1, -1):
        if gears[i + 1][-2] == gears[i][2]:
            break

        left_d *= -1
        rotated_gears.append((i, left_d))

    # Right
    right_d = d
    for i in range(n + 1, T):
        if gears[i - 1][2] == gears[i][-2]:
            break

        right_d *= -1
        rotated_gears.append((i, right_d))

    for i, j in rotated_gears:
        rotate(gears[i], j)


ans = 0
for gear in gears:
    if gear[0] == '1':
        ans += 1
print(ans)