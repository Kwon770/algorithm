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


import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

N, M = map(int, readline().split())
r, c, d = map(int, readline().split())
arr = []
for i in range(N):
    arr.append(list(map(int, readline().split())))

ans = 0
cleaned = [[False] * M for _ in range(N)]
end = False
while not end:
    if not cleaned[r][c]:
        cleaned[r][c] = True
        ans += 1
        continue

    cleanable = False
    for i in range(1, 5):
        nd = (d - i) % 4
        nr = r + dr[nd]
        nc = c + dc[nd]
        if nr < 0 or nc < 0 or nr >= N or nc >= M or arr[nr][nc] == 1:
            continue
        if not cleaned[nr][nc]:
            cleanable = True

            d = nd
            r = nr
            c = nc
            break

    if not cleanable:
        back_d = (d + 2) % 4
        nr = r + dr[back_d]
        nc = c + dc[back_d]
        if nr < 0 or nc < 0 or nr >= N or nc >= M or arr[nr][nc] == 1:
            end = True
            continue

        r = nr
        c = nc

print(ans)