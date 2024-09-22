# Greedy - Q4 만들 수 없는 금액 (P314)

# 비슷한 유형, 같은 점화식을 사용하는 문제 (2011 KOI 초등부 3번, 2437 저울 G3) : https://www.acmicpc.net/problem/2437

# 이 문제는 주어진 숫자들의 합 조합으로 만들 수 없는 숫자를 구하는 법에 대한 점화식을 깨닫는 것이 핵심임
# 점화식에 대한 보충 설명 : https://www.acmicpc.net/board/view/45841
# [점화식의 다음 규칙들을 지키는 숫자의 조합이라면 점화식이 보장하는 결과를 지키는 조합들이다]
# 1. a[i]가  X + a[i-1]보다 작거나 같으면, X + a[i-1] 미만의 숫자들을 숫자의 조합합으로 만들 수 있다.
# 2.            "                크면, X + a[i-1]을 만들 수 없다.
# 특별한 수학적 원리가 있는 것이 아니라 점화식이 숫자 조합을 보장한다.

import sys
input = sys.stdin.readline


def solution():
    n = int(input())
    data = list(map(int, input().split()))
    data.sort()

    target = 1
    for x in data:
        if target < x:
            break

        target += x

    return target


print(solution())