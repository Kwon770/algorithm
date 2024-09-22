# https://www.acmicpc.net/problem/1789
# 1789 수들의 합
# Memory : 30864 KB / Time : 76 ms

import sys; readline = sys.stdin.readline

def solution():
    S = int(readline())
    n = 0
    for i in range(1, S + 1):
        n += i

        if S == n:
            return i
        elif S < n:
            return i - 1


    return answer

print(solution())