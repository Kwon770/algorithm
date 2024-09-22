# https://www.acmicpc.net/problem/2252
# 2252 줄 세우기
# Memory: 40420 KB, Time: 164 ms


"""
학생들을 정렬시켜야 하지만, 주어진 비교 결과(규칙)만 만족하면 된다.
학생 수는 최대 3만, 규칙 수는 10만으로 배열에 제한이 있거나 탐색에 제한이 있진 않다.

- 규칙에 맞게 학생의 위치를 특정 학생의 앞 혹은 뒤로 위치시킨다 => insert 는 무조건 TLE라고 생각한다.
- 규칙을 순회하며 숫자끼리 swap한다거나, 대략적인 위치를 전처리한다 => 특정 숫자의 위치 선정을 하나의 규칙안에서만 판단할 수 없다.
    ex) 1 3
        2 5
        1 5
    - 1을 움직일 때 3도 같이 움직여야하며, (1, 3)과 2의 위치 관계는 후속 규칙에서 어떻게 규정할지 모른다.

=> 임의로 숫자를 순회하되 이 숫자보다 앞에 있을 수 있는 모든 숫자를 확인한다. 더 이상 앞에 있을 숫자가 없다면, 순서에 넣는다.
    ex) 1 3
        3 4
        2 1
    => 앞에 있을 수 있는 숫자를 찾는 과정을 dfs로 진행 (마지막에서 이미 추가된 (1, 3)의 순서를 뒤엎는 규칙이 
        있더라도, dfs를 통해 (1, 3) 규칙을 순회하는 과정에서 이미 검토한다.)
"""""

import sys;

readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N, M = map(int, readline().split())
rules = [[] for _ in range(32001)]
for _ in range(M):
    A, B = map(int, readline().split())
    rules[B].append(A)


def dfs(num):
    global line, visited

    if visited[num]: return
    visited[num] = True

    for front in rules[num]:
        if not visited[front]:
            dfs(front)

    line.append(num)


line = []
visited = [False] * (32001)
for i in range(1, N + 1):
    dfs(i)

print(" ".join(map(str, line)))