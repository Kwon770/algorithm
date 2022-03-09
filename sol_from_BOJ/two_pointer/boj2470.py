# https://www.acmicpc.net/problem/2470
# 2470 두 용액
# Memory : 41896 KB / Time : 140 ms

# 1초 제한에 N=100,000 이므로, 완전탐색 O(N^2) 풀이는 불가능하다. 2가지 방법이 있는데
# 1. 전부 탐색하지만 짝을 찾는 과정을 이분탐색을 통해 완전탐색보다 단축시킨다. (/sol_from_BOJ/binary_search/boj2467.py)
# 2. 문제의 원리를 이용하여 투포인터를 통해 푼다.

# 2-1. 두 숫자의 합으로 짝이 이루어지며, 중복될 수도 없으므로 투포인터가 양쪽에서 확인하면 효율적이다.
# 2-2. 포인터의 이동은 중간으로 이동하개 되는데, 중간으로 이동한다는 것은 절대값이 작아지는 것을 의미하므로 포인터 중 절대 값이 큰 포인터를 이동시키면 된다.

import sys; readline = sys.stdin.readline

def solution():
    N = int(readline())
    materials = list(map(int, readline().split()))
    materials.sort()

    min_val = 9000000000
    ans = [0, 0]
    l = 0
    r = N - 1
    while l != r:
        val = abs(materials[l] + materials[r])
        # print(val, materials[l], materials[r])
        if min_val > val:
            min_val = val
            ans = [materials[l], materials[r]]

        if abs(materials[l]) > abs(materials[r]):
            l += 1
        else:
            r -= 1

    ans.sort()
    return ' '.join(map(str, ans))

print(solution())