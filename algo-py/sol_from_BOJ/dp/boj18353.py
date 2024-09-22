# https://www.acmicpc.net/problem/18353
# 18353 병사 배치하기
# Memory : 30864 KB, Time : 640 ms

# 문제의 기본 아이디어는 '가장 긴 증가하는 부분 수열 LIS'로 알려진 전형적인 DP 문제 아이디어다.
# "memo[i] = array[i]를 마지막 원소로 가지는 부분 수열의 최대 길이" 라고 정의하면 된다.

# LIS의 길이를 찾기위해 2중 for문과 메모이제이션을 사용중이지만, 시간복잡도가 최선인 방법은 아니다.
# bisect_left(), 이진탐색을 이용해서 LIS 자체를 찾고, 그 길이를 이용하면 시간복잡도가 단순해진다.

import sys
input = sys.stdin.readline

def solution():
    n = int(input())
    soldiers = list(map(int, input().split()))

    memo = [1] * n

    for i in range(n-2, -1, -1):
        for j in range(n-1, i, -1):
            if soldiers[j] < soldiers[i]:
                memo[i] = max(memo[i], memo[j]+1)

    return n - max(memo)

print(solution())