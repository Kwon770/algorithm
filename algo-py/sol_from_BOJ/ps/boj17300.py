# https://www.acmicpc.net/problem/17300
# 172300 패턴
# Memory : 30840 KB / Time : 68 ms

# 적합한 패턴의 규칙의 핵심을 파악하고 구현력을 발휘하는게 핵심

import sys; readline = sys.stdin.readline

def toAxis(idx):
    idx -= 1
    r = idx // 3
    c = idx % 3

    return r, c

def toIdx(r, c):
    return (r * 3) + c + 1

L = int(input())
arr = list(map(int, readline().split()))
visited = [False for _ in range(10)]
yes = True

visited[arr[0]] = True
for i in range(1, L):
    if visited[arr[i]]:
        yes = False
        break

    visited[arr[i]] = True

    pr, pc = toAxis(arr[i - 1])
    nr, nc = toAxis(arr[i])
    crossIdx = -1
    if pr == nr and abs(pc - nc) == 2:
        crossIdx = toIdx(nr, (pc + nc) // 2)

    elif pc == nc and abs(pr - nr) == 2:
        crossIdx = toIdx((pr + nr) // 2, nc)

    elif abs(pc - nc) == 2 and abs(pr - nr) == 2:
        crossIdx = toIdx((pr + nr) // 2, (pc + nc) // 2)

    if crossIdx != -1 and not visited[crossIdx]:
        yes = False
        break

if yes:
    print("YES")
else:
    print("NO")