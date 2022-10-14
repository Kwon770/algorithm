# https://codeforces.com/contest/1742/problem/C
# C. Stripes
# Memory : 9500 KB / Time : 405 ms

# 문제는 단순했으나 처음 풀이를 설계할 때 가로는 무조건 R, 세로는 무조건 B라는 조건을 놓쳤고,
# 이후에 조건을 확인했지만 이 조건이 반례를 만든다는 것을 찾이 못했다
# 반례: (B)
# RRRRBRRR
# RRRRBRRR
# RRRRBRRR
# RRRRBRRR
# RRRRBRRR
# RRRRBRRR
# RRRRBRRR
# RRRRBRRR

# 마지막으로 색칠한 경우 한 줄이 전부 같은 색이라는 점을 이용했지만, 온전한 한 줄을 발견하면 바로 종료되는 풀이이므로
# 가로는 R, 세로는 B라는 조건을 넣지 않으면 반례와 같은 경우 제대로 B를 출력하지 못한다.

# 문제의 조건을 간과해서 엣지케이스를 만들고 이를 찾지못하는 실수가 반복되고 있다. 유의해야할 듯 하다.

import sys; readline = sys.stdin.readline

t = int(readline())
for _ in range(t):
    blank = input().rstrip()
    grid = []
    for i in range(8):
        grid.append(input().rstrip())


    found = False
    for i in range(8):
        if grid[i][0] != 'R':
            continue

        isBroken = False
        for j in range(8):
            if grid[i][j] != "R":
                isBroken = True
                break

        if not isBroken:
            found = True
            print("R")
            break

    if found:
        continue

    for i in range(8):
        if grid[0][i] != 'B':
            continue

        isBroken = False
        for j in range(8):
            if grid[j][i] != "B":
                isBroken = True
                break

        if not isBroken:
            print("B")
            break