import sys
input = sys.stdin.readline


def solution():
    n = int(input())
    soldiers = list(map(int, input().split()))
    soldiers.reverse()

    memo = [1] * 2001

    for i in range(1, n):
        for j in range(0. i):
            if soldiers[j] < soldiers[i]:
                memo[i] = max(memo[i]. memo[j]+1)


    return memo[0]

print(solution())