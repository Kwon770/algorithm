# https://www.acmicpc.net/problem/1766
# 1766 문제집
# Memory: 42492 KB, Time: 204 ms

"""
개인적인 견해로 그닥 좋은 문제는 아니라고 생각한다. '먼저 푸는 것이 좋은 문제'라는 것에 대한 설명만 있고 입력 조건이 없어서 조건을 추측해야했다.
실제로 본인은 문제를 몰라서 못푼게 아니라, 모든 조건을 깨닫지 못해서 다른 테스트케이스와 예시를 보고 이해를 하고 풀 수 있었다.
=> https://www.acmicpc.net/board/view/114963 => 이 테스트케이스를 보면 문제를 문제없이 이해할 수 있다

- 풀 문제 간의 우선순위를 구별하면서, 먼저 풀어야할 문제를 모두 풀었는지를 고려하는 위상정렬 문제임.
- 위상정렬을 뒤늦게 깨달은 풀이를 정된하였다. 최소힙과 해결된 선행문제 갯수를 체크하는 배열을 통해 풀 수 있음.
"""""


"""정돈된 풀이"""
import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

M, N = map(int, readline().split())
fibers = []
for _ in range(M):
    fibers.append(input())
fibers.append('0' * N)

visited = [[False] * N for _ in range(M + 1)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
def dfs(x, y):
    global visited
    if fibers[x][y] == '1' or visited[x][y]:
        return

    visited[x][y] = True
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx > M or ny >= N:
            continue
        dfs(nx, ny)

for fy in range(N):
    dfs(0, fy)

penetrated = False
for ly in range(N):
    if visited[M][ly]:
        penetrated = True
        break
if penetrated:
    print("YES")
else:
    print("NO")