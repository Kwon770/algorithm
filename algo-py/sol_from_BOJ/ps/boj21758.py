# https://www.acmicpc.net/problem/21758
# 21758 꿀따기
# Memory: 42340 KB, Time: 172ms

# 가능한 경우의 수를 나누어 그리디하게 풀려고 시도하였지만, 엣지케이스가 있었다.
# 1. 벌1과 꿀통이 각각 좌우에 있고, 벌2는 그 사이 중에 꿀이 최소인 곳에 배치된다. (가장 최소의 꿀이 제외되는 것이 최선일 것이라는 그리디)
# 2. 벌1 벌2가 붙어서 좌 혹은 우에 있고, 꿀통은 반대편에 배치한다.
# 3. 벌1 벌2가 각각 좌우에 있고, 꿀통은 그 사이 중 꿀이 최대인 곳에 배치된다. (꿀xhd이 있는 곳은 2번 채취)
# 하지만 WC였다. 추측컨데, 1번에 엣지케이스가 있는 듯 하다. (최소인 꿀을 제외하고 더 적은 길이를 채취하는 것 보다, 더 긴 길이를 채취하는 것이 최종적으로 최대 인 경우)
# 결국 실패하고 풀이를 봤다.

# 더 직관적이고 간편하게 꿀통의 위치에 따라 나누자.
# 1. 꿀통이 제일 왼쪽인 경우 => 벌1은 무조건 가장 오른쪽이며, 벌2는 그 사이 중 총합이 최대가 되는 곳을 모두 확인한다.
# 2. 꿀통이 제일 오른쪽인 경우 => ..
# 3. 꿀통이 사이인 경우 =>

# ! 반복되는 합계 계산을 최적화하기 위해, 부분합을 이용한다.
# ! 제일 오른쪽 혹은 왼쪽에 존재하는 벌1의 채취량은 벌2의 위치에 따라 달라진다. 따라서 이를 벌1의 채취량 계산으로 생각하지 않고,
# 벌2의 위치산정 중에 총합 계산 과정에서 벌2 위치의 꿀을 빼는 방식이 깔끔한 논리다.

# ! 관측되는대로 무턱 문제(경우의 수)를 카테고리화하지 말고, '문제 논리'를 최대한 단순화 및 카테고리화하자.
# ! 문제의 범위가 그렇게 크지않았다. 경솔하게 문제를 추측해서, '문제 풀이 논리'를 단순하게 생각하지 말고 예외를 잘 생각하자.
# 가능하다면, 큰 고민없이 브루트포스식으로 바로 가는게 오답 확률이 적다고 생각한다.


import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
INF = sys.maxsize

N = int(input())
honey = list(map(int, readline().split()))

subtotal = [honey[0]]
for i in range(1, N):
    subtotal.append(subtotal[i - 1] + honey[i])

max_honey = -1
for i in range(1, N - 1):
    max_honey = max(max_honey, subtotal[N - 2] + subtotal[i - 1] - honey[i])

for i in range(1, N - 1):
    max_honey = max(max_honey, subtotal[N - 1] - honey[0] + subtotal[N - 1] - subtotal[i] - honey[i])

# for i in range(1, N - 1):
#     max_honey = max(max_honey, subtotal[N - 2] - honey[0] + honey[i])
max_honey = max(max_honey, subtotal[N - 2] - honey[0] + max(honey[1:N-1]))

print(max_honey)