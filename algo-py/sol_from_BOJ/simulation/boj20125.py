# https://www.acmicpc.net/problem/20125
# 20125 쿠키의 신체 측정
# Memory: 31520 KB, Time: 148 ms
# Memory: 40196 KB, Time: 300 ms

"""
구현 문제지만, 주어진 규칙(쿠키의 몸의 형태)를 얼마나 잘 단순화시키고 잘 활용하냐에 따라 난이도가 달라졌다

첫 풀이는 심장의 위치를 기준으로 각 파트의 좌표를 기준으로 길이를 알기위한 탐색을 진행하는, (순회 + 구현) 풀이였다.
하지만 굉장히 비효율적이고 복잡한 풀이였다.

두 번째 풀이는 규칙을 잘 단순화하고 활용한 풀이인데, 결국 요구하는 것은 심장의 '위치'와 각 파타의 '길이'다
그리고
- 머리는 늘 한 칸이며, 심장은 늘 머리 아래에 있다.
- 몸의 각 파트는 일정한 형태를 유지하고 있기 때문에, 몸 파트의 좌우 혹은 다른 파트간의 위치 관계를 잘 이용하면 길이는 일부 단서만으로 구할 수 있다.

!! 구현이라도 단순히 탐색 혹은 순회만 주구장창 넣는게 아니라, 잘 분석해야한다는 교훈 !!
"""""

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

N = int(input())
cookie = []
for _ in range(N):
    cookie.append(readline().rstrip())


head = (-1, -1)
arm_l = -1
arm_r = -1
body_b = -1
leg_l = -1
leg_r = -1

for r in range(N):
    for c in range(N):
        if cookie[r][c] == '_':
            continue

        # 머리는 늘 먼저
        if head[0] == -1:
            head = (r, c)

        # 머리 아래는 팔
        elif r - 1 == head[0]:
            # 팔은 왼쪽부터
            if arm_l == -1:
                arm_l = c
            else:
                arm_r = c

        # 머리랑 같은 col, body의 col이면 계속 그 높이를 갱신해나감
        elif c == head[1]:
            body_b = r

        # 머리의 좌우인지만 확인하고 갱신하면 결국 다리, 팔은 위에서 거르니까 애초에 팔이랑 헷갈리지 않음
        # 몸통과 마찬가지로 높이를 갱신해나감
        elif c == head[1] - 1:
            leg_l = r
        elif c == head[1] + 1:
            leg_r = r

print(head[0] + 1 + 1, head[1] + 1)
print(head[1] - arm_l, arm_r - head[1], body_b - head[0] - 1, leg_l - body_b, leg_r - body_b)


""" 순회 + 구현
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

heart_r = -1
heart_c = -1
def isHeart(r, c):
    return heart_r == r and heart_c == c


def isThere(r, c):
    if r < 0 or c < 0 or r >= N or c >= N:
        return False

    if cookie[r][c] == '_':
        return False
    else:
        return True


visited = [[False for _ in range(N)] for _ in range(N)]

#### 정답은 인덱스 + 1 !!!
isMetHead = False
lengths = [0, 0, 0, 0, 0]
for r in range(N):
    for c in range(N):
        if visited[r][c]: continue

        visited[r][c] = True
        if cookie[r][c] == '_':
            continue

        dir = -1
        idx = -1
        if not isMetHead:
            isMetHead = True
            heart_r = r + 1
            heart_c = c
            visited[heart_r][heart_c] = True
            continue

        # right arm
        elif isHeart(r, c - 1):
            dir = 1
            idx = 1
        # left arm
        elif isThere(r, c + 1):
            dir = 1
            idx = 0
        # wirst
        elif isHeart(r - 1, c):
            dir = 2
            idx = 2
        # left leg
        elif isThere(r - 1, c + 1):
            dir = 2
            idx = 3
        # right leg
        elif isThere(r - 1, c - 1):
            dir = 2
            idx = 4

        nr = r
        nc = c
        length = 0
        while isThere(nr, nc) and not isHeart(nr, nc):
            print(idx, nr, nc)
            visited[nr][nc] = True

            length += 1
            nr += dr[dir]
            nc += dc[dir]

        lengths[idx] = length

print(heart_r + 1, heart_c + 1)
print(' '.join(map(str, lengths)))
"""
