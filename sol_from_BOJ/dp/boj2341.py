# https://www.acmicpc.net/problem/2341
# 2341 팩스
# Memory : 30840 KB / Time : 68 ms

# 계산식에서 W 가중치로 인해 최선인 값 선택이 일정하지 않아서, 그리디로 풀 수 없다.
# 매 단계의 압축 형태는 이후에 영향을 미치기때문에 단순 탐색으로 안되고, 완전탐색으로 풀자면 복잡도가 4^50이다.
# 따라서 DP가 남고 압축의 변화에 영향을 미치는 전 단계와 현 단계를 캐싱을 이용해 4*4 가지를 모두 고려하여서 풀 수 있다.
# (현 단계 4가지가 전 단계 4가지 중 최적을 찾아서 모두 계산하고 정하여, 마지막 단계의 4가지중 최소를 찾는 것 이므로 그리디와는 다르다)
# 매번 모든 경우의 수를 고려한다고 하더라도 복잡도는 50*4*4 로 대폭 감소한다.

import sys; readline = sys.stdin.readline

cache = [[-1 for _ in range(4)] for _ in range(N)]
backtracking = [[-1 for _ in range(4)] for _ in range(N)]
compression_level = [1, 86, 172, 256]
def dp():
    global cache
    global backtracking
    global compression_level
    for i in range(4):
        cache[0][i] = abs(compression_level[i] - image[0]) + W * 2

    for i in range(1, N):
        for nc in range(4):

            min_comp = 9876543210
            for pc in range(4):
                comp = cache[i - 1][pc]
                if pc == nc:
                    comp += abs(compression_level[nc] - image[i]) + W * 1
                else:
                    comp += abs(compression_level[nc] - image[i]) + W * 3

                if min_comp > comp:
                    min_comp = comp
                    backtracking[i][nc] = pc
            cache[i][nc] = min_comp


N, W = map(int, readline().split())
image = []
for _ in range(N):
    image.append(int(readline()))

dp()

min_val = 9876543210
last_comp = 0
for i in range(4):
    if min_val > cache[-1][i]:
        min_val = cache[-1][i]
        last_comp = i
print(min_val)

compression = [last_comp]
for i in range(N - 1, 0, -1):
    compression.append(backtracking[i][last_comp])
    last_comp = backtracking[i][last_comp]
compression.reverse()

compression_code = ["00", "01", "10", "11"]
compressed = [compression_code[compression[0]]]
for i in range(1, len(compression)):
    if compression[i - 1] == compression[i]:
        compressed.append("0")
    else:
        compressed.append("1")
        compressed.append(compression_code[compression[i]])
print("".join(compressed))
