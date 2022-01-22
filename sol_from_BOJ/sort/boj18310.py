# https://www.acmicpc.net/problem/18310
# 18310, 안테나
# Memory : 53508 KB, Time : 156 ms

# 가장 중간에 있는 집에 안테나를 설치하는 것이 늘 최선이므로, 가장 중간에 있는 집을 찾으면 끝이다
# 가장 중간 외에 반례가 있을 것 같은 느낌이 들지만, 반례는 없는 것이 힘든 점이다.

import sys
input=sys.stdin.readline

n = int(input())
homes = sorted(list(map(int, input().split())))
if len(homes) % 2 == 0:
    print(homes[len(homes) // 2 - 1])
else:
    print(homes[len(homes) // 2])