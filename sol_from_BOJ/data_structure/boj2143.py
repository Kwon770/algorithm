# https://www.acmicpc.net/problem/2143
# 2143 두 배열의 합
# Memory: 73244 KB, Time: 384 ms


"""
이 문제는 DP, 투포인터 등등으로 최적화할 수 있는 여지가 없다.
1. 부 배열이 연속된 순열의 합이다.
2. 부 배열의 합이 같더라도, 합에 사용된 부 배열 원소가 다르면 다른 경우의 수다.
3. (-10억 <= T <= +10억)이므로, 모든 값을 원소로하는 배열캐싱이 불가능하다.

합이 T가되는 모든 부 배열 쌍의 개수를 구하기 위해서, A와 B모두를 순회하면서 찾아야 한다.
=> 최적화를 위해, A를 계산한 값들을 전처리하고, B에서 순회하는 동안 답을 계산한다.
    => 결국 필요한 값은 특정 숫자를 만들 수 있는 A 부 배열 쌍의 갯수이므로, 이를 Dict으로 관리한다.
    => 다른 풀이에서는 **부 배열의 합을 리스트에 담고, 이진탐색 left right를 구하여, 부 배열 쌍의 갯수**를 구한다.
        => Dict이 (x in s) (get, set) 모두 O(1)으로 시간복잡도 상으로는 현재 풀이가 더 효율적
        => 풀이 자체는 흥미로움. 기억해두기

!! T와 배열의 원소는 0 혹은 음수를 포함한다 !!
반례를 찾던중 문제의 QnA를 오독해서, 0 혹은 음수가 없다고 생각하고 풀어서, 계속 틀렸다
- 애초에 T의 범위는 (-10억 <= T <= +10억)
- 배월 원소의 범위는 "절댓값" 100,0000를 넘지않는 정수
이를 조심하자

"""""

import sys;

readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

T = int(readline())
N = int(readline())
A = list(map(int, readline().split()))
M = int(readline())
B = list(map(int, readline().split()))

dict_a = dict()
for i in range(N):
    sum_a = 0
    for j in range(i, N):
        sum_a += A[j]

        if sum_a in dict_a:
            dict_a[sum_a] += 1
        else:
            dict_a[sum_a] = 1

ans = 0
for i in range(M):
    sum_b = 0
    for j in range(i, M):
        sum_b += B[j]

        need_a = T - sum_b

        if need_a in dict_a:
            ans += dict_a[need_a]

print(ans)
