# https://www.acmicpc.net/problem/14719
# 14719 빗물
# Memory : 30864 KB / Time : 80 ms

# 빗물이 잠기는 공간인지 확인을 해서 계산을 해야하는 구현 문제였다.
# for문 순회 논리에 너무 습관이 들었는지 당연히 순회하면서 빗물이 잠길 수 있는 높이를 감지하여 계산하는 식으로 구현했지만, 실패했다.
# 그 다음으로 도전했던 방법은 정석과 가장 근접한 방식이였는데, 확인하는 위치를 기준으로 좌우의 벽의 높이를 확인하여 물이 잠기는지 확인하는 방법이였다.
# 문제는 2차원 예시에 몰입한 나머지 2차원 배열의 모든 칸을 이와 같은 방식으로 확인한다고 생각했고, 이 방법대로면 O(N^3)이다.

# 결국 정석은 각 줄별로 좌우의 벽의 높이를 확인하고, 잠기는 높이를 계산하면 그것이 잠기는 빗물의 양이다. O(N^2)으로 충분한 것이다.
# 1. 순회하면서 값을 캐싱하여 계산하는 방식을 집착하는 것을 버려야 한다.
# 2. 문제의 설명이나 예시, 그림에 너무 빠져들지 말자

import sys; readline = sys.stdin.readline

def solution():
    H, W = map(int, readline().split())
    walls = list(map(int, readline().split()))

    answer = 0
    for i in range(1, W - 1):
        left = max(walls[0:i])
        right = max(walls[i + 1:W])

        if left <= walls[i] or right <= walls[i]:
            continue
        else:
            height = min(left, right)
            answer += height - walls[i]

    return answer

print(solution())