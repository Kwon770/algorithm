# https://www.acmicpc.net/problem/2467
# 2467 용액
# Memory : 43964 KB / Time : 200 ms

# 이분 탐색을 응용한다는 논리는 정답이였지만, 처리해야하는 예외를 제대로 캐치못하고 이를 깔끔히 처리하지도 못하여 풀지못했다
# 결국 이분 탐색을 응용 과정에서 예외처리를 깔끔하게 처리하는 코드를 참고하여 풀었다.

# 1초 제한에 N=100,000 이므로, 완전탐색 O(N^2) 풀이는 불가능하다. 2가지 방법이 있는데
# 1. 전부 탐색하지만 짝을 찾는 과정을 이분탐색을 통해 완전탐색보다 단축시킨다.
# 2. 문제의 원리를 이용하여 투포인터를 통해 푼다. (/sol_from_BOJ/two_pointer/boj2467.py)

# 1-1. 0에 가장 가까운 수를 비교하기위해 abs, 절대값으로 비교하면 된다.
# 1-2. 이분탐색 (결과)와 (결과 -1)인 두 곳만 비교하면 되지만, 일일이 예외사항을 처리하면 상당히 복잡해진다.
#    두 곳중 하나만 비교하게 된다는 점과 여러 조건을 비교해야한다는 점을 이용해서 for문과 continue를 통해서 깔끔하게 처리했다.

import sys; readline = sys.stdin.readline
import bisect

def solution():
    min_val = 90000000000
    answer = []
    N = int(readline())
    materials = list(map(int, readline().split()))
    for i in range(N):

        idx = bisect.bisect_left(materials, -materials[i])
        for j in range(idx-1, idx+1):
            if j < 0 or j >= N or i == j:
                continue

            cur_val = abs(materials[i] + materials[j])
            if min_val > cur_val:
                min_val = cur_val
                answer = [materials[i], materials[j]]

    if answer[0] > answer[1]: answer[0], answer[1] = answer[1], answer[0]
    return ' '.join(map(str, answer))

print(solution())