# https://www.acmicpc.net/problem/1540
# 1540 정사각형의 개수
# Memory : 72512 KB / Time : 532 ms

# 처음에 문제를 이해하는데도 어려움을 겪었지만, 패턴을 찾다가 결국 실패해서 블로그의 풀이를 참고하였다.
# https://ongveloper.tistory.com/337

# 결국 내 패착은 패턴을 더 단순화하지 못하였다.
# 사각형이 시계방향으로 추가되는 형태로 점을 추가하며 패턴을 파악하였더니,
# 넓이1 사각형 + 넓이2이상 사각형들을 계산하는 로직으로 분리되었고, 난잡해서였는지 테케도 제대로 통과시키지 못했다.

# 블로그에서는 우하단으로 일관되게 점을 추가하며, 각 점의 사각형 개수의 패턴을 통해 사각형이 추가되는 개수의 패턴을 파악했다.
# 이를 응용해서, 점 개수의 제곱근을 기준으로 잡고 패턴과의 연관성을 만들어서 간략화하였다.
# 연관성 파악과 코드 작성에도 너무 긴 시간이 들어서, 올바른 코드인지 확신이 가지는 않는다.

import sys; readline = sys.stdin.readline
from math import sqrt

n = int(readline())
dp = [0] * 1000001

step = 1
squares = 0
for i in range(2, n + 1):
    dp[i] = dp[i - 1] + squares

    squares += 1
    if squares == step:
        squares = 0

    if sqrt(i) == step + 1:
        dp[i] += step
        step += 1
        squares = 0

print(dp[n])