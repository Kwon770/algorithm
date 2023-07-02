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
import heapq


N, M = map(int, readline().split())
a2b = [[] for _ in range(N + 1)]
entry = [0] * (N + 1)
for _ in range(M):
    A, B = map(int, readline().split())
    a2b[A].append(B)
    entry[B] += 1

problems = []
for i in range(1, N + 1):
    if entry[i] == 0:
        heapq.heappush(problems, i)


sequence = []
while problems:
    p = heapq.heappop(problems)
    sequence.append(p)

    for next in a2b[p]:
        entry[next] -= 1
        if entry[next] != 0:
            continue

        heapq.heappush(problems, next)

print(" ".join(map(str, sequence)))



""" 내 풀이
import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
import heapq

def dfs(node):
    global visited, problems

    if visited[node] == True:
        return

    visited[node] = True
    if len(b2a[node]) == 0:
        heapq.heappush(problems, node)
        return

    for next in b2a[node]:
        dfs(next)


N, M = map(int, readline().split())
b2a = [[] for _ in range(N + 1)]
a2b = [[] for _ in range(N + 1)]
for _ in range(M):
    A, B = map(int, readline().split())
    a2b[A].append(B)
    b2a[B].append(A)


problems = []
visited = [False] * (N + 1)
for i in range(1, N + 1):
    dfs(i)

count = [0] * (N + 1)
sequence = []
while problems:
    p = heapq.heappop(problems)
    sequence.append(p)

    for next in a2b[p]:
        count[next] += 1
        if count[next] != len(b2a[next]):
            continue

        heapq.heappush(problems, next)

print(" ".join(map(str, sequence)))
"""