# https://www.acmicpc.net/problem/2653
# 2653 안정된 집단
# Memory: 30840kb / Time: 68ms

# 문제 설명과 조건이 복잡하고 길게 설명되어 있는데, 핵심은 간단하다.
# 1. 사람 간의 우호도가 다르면 불안정한 집단이다.
# 이 부분을 간접적으로 표현하고 있는데, 서로 좋아하는 사람끼리 그룹을 나누면 안정된 집단을 만들 수 있는데 서로의 우호도가 다르면 그룹을 나눌 수가 없다.
# 2. DFS로 탐색하면서 그룹화하고 그 결과를 저장한다.
# 한 번의 DFS 탐색에서 찾아지는 사람은 같은 그룹이다.

import sys; readline = sys.stdin.readline

n = int(readline())
relation = [list(map(int, readline().split())) for _ in range(n)]

stable = True
for i in range(n):
    for j in range(i + 1, n):
        if relation[i][j] != relation[j][i]:
            stable = False
            break
    if not stable: break

visited = [False] * n
group = []
count = 0
for i in range(n):
    if visited[i]:
        continue

    visited[i] = True
    count += 1
    group.append([i+1])
    g_index = count - 1
    for j in range(n):
        if relation[i][j] != 0 or i == j:
            continue

        group[g_index].append(j+1)
        visited[j] = True

for g in group:
    if len(g) < 2:
        stable = False
        break

if stable:
    print(count)
    for g in group:
        print(*g)
else:
    print(0)