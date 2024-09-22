# https://www.acmicpc.net/problem/5557
# 5557 1학년
# Memory : 30840 KB / Time : 68 ms

# DP의 전형적인 문제 패턴
# 단순하게 문제를 풀 수 있는 경우를 생각했을때, 고려해야하는 경우의 수가 무수히 많이 뻗어나가서 탐색으로 풀 수 없다고 판단된다.

# 1. 연산자는 +와 -이므로, 이전까지의 수식에서 현재 숫자를 + 혹은 -힌 경우를 고려한다
# 2. 생성한 수식을 통해 최종적으로 고혀할 대상은 계산 결과이므로, 중간 생성된 긱 수식들도 계산값으로 분류한다.
# 3. 모든 수식을 0 ~ 20사이의 값으로 제한했기 때문에, 수식의 계산값들로 캐싱이 가능하다.


import sys; readline = sys.stdin.readline

N = int(readline())
arr = list(map(int, readline().split()))

cache = [[0 for _ in range(21)] for _ in range(N - 1)]
cache[0][arr[0]] = 1

for i in range(1, N - 1):
    for j in range(21):
        if cache[i - 1][j] == 0:
            continue

        if 0 <= j + arr[i] <= 20:
            cache[i][j + arr[i]] += cache[i - 1][j]

        if 0 <= j - arr[i] <= 20:
            cache[i][j - arr[i]] += cache[i - 1][j]

print(cache[-1][arr[-1]])