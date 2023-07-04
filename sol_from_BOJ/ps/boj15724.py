# https://www.acmicpc.net/problem/15724
# 15724 주지수
# Memory: 73180 KB, Time: 920 ms

"""
단순한 요구사항이지만, K개의 합을 구하는 조건으로 인해 단순한 풀이로는 TLE가 발생한다.

- 매 번 직접 합을 계산 할 경우: NMK (대략 1000억)
- 1차원 부분합을 사용할 경우: NK (대략 1억)
  - 이 정도는 시도해볼한다고 생각했지만, Python3 채점기준, TLE
- 2차원 부분합을 사용할 경우: K (대략 10만)

!! 2차원 부분합 테크닉에 대해서 기억하자 !!
- 부분합에 대한 개념이 없었어서 나름대로의 DP를 적용하였지만, 1차원 부분합이였기 때문에 TLE를 발생했다.
- 부분합 배열을 0부터 N까지의 원소를 만들고, 0으로 초기화하였다
  - 첫 번째 원소의 부분합 계산에 대핸 로직의 예외를 만들 필요가 없어짐
"""""


"""정돈된 풀이"""
import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N, M = map(int, readline().split())
subsum = [[0 for _ in range(M + 1)] for _ in range(N + 1)]
for i in range(1, N + 1):
    arr = list(map(int, readline().split()))

    for j in range(1, M + 1):
        subsum[i][j] = subsum[i - 1][j] + subsum[i][j - 1] - subsum[i - 1][j - 1] + arr[j - 1]

K = int(input())
for _ in range(K):
    x1, y1, x2, y2 = map(int, readline().split())

    total = subsum[x2][y2] - subsum[x1 - 1][y2] - subsum[x2][y1 - 1] + subsum[x1 - 1][y1 - 1]
    print(total)