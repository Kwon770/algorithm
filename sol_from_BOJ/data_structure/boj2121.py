# https://www.acmicpc.net/problem/2121
# 넷이 놀기, 2121
# Memory: 111128 KB, Time: 1364 ms

# 처음에는 가로길이가 A보다 세로길이가 B보다 큰 모든 사각형의 경우의 수를 찾는 문제로 오독해서 한없이 어려웠지만,
# 제대로 읽고나서는 파이썬에게는 쉬운 문제였다.

# 순회하는 좌표 본인 제외, 찾고자하는 3개의 점이 존재하는지만 확인하면 되므로, set을 이용했다.
# 몰랐지만, set은 index접근만 안되지 for interate는 가능했다.

# set을 쓰지 않는다면, 좌표가 존재하는지 찾기위해 이분탐색을 쓸 수도 있을 것이다.
# 좌표 최대 갯수가 500000개이므로, 여러 개의 집합,리스트를 만들지 않는 이상 문제없을 것이다.
# 좌표 값의 범위가 크지만, 문제 풀이에는 영향이 없다. => 값을 배열의 인덱스로 전처리하는 풀이를 막기위함 인듯.

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N = int(readline())
A, B = map(int, readline().split())
pos = set()
for _ in range(N):
    x, y = map(int, readline().split())
    pos.add((x, y))

ans = 0
for p in pos:
    if (p[0] + A, p[1]) in pos and \
            (p[0], p[1] + B) in pos and \
            (p[0] + A, p[1] + B) in pos:
        ans += 1

print(ans)
