# https://www.acmicpc.net/problem/1038
# 1038 감소하는 수
# Memory : 30864 KB / Time : 68 ms

# 감소하는 수는 조합과 일치하는 속성이 있다. 따라서 나는 itertools.combinations을 응용해서 풀었다.
# itertools.combinations은 """원본 배열 순서대로 조합을 만들기 때문에""" 9~0 순서대로 배열을 주면 감소하는 수인 조합을 만들 수 있었다.

import sys; readline = sys.stdin.readline
from itertools import combinations

def solution():
    N = int(readline())

    if N < 10:
        return N

    cnt = 9
    while True:
        for i in range(2, 11):
            arr = ['9', '8', '7', '6', '5', '4', '3', '2', '1', '0']
            comb = list(combinations(arr, i))
            cnt += len(comb)
            if cnt >= N:
                cnt -= len(comb)
                return int(''.join(comb[cnt - N]))

        return -1

print(solution())