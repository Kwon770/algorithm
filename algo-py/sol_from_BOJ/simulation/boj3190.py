# https://www.acmicpc.net/problem/3190
# 3190 뱀
# Memory : 34536 KB , Time : 128 ms

# 고려할게 많은 구현 문제이다.
# 리스트에 들은 튜플을 확인해야하는 부분이 많았는데, (튜플이 한 번에 두 개의 원소를 가짐)
# 1. row, column 모두 일치하는 튜플의 존재 확인 : (nr, nc) in snake
# 2. 첫 번째 원소만 일치하는 튜플들을 찾기 : [r[1] for r in rotations if r[0] == time]:

import sys; input = sys.stdin.readline
import math
import itertools
import collections

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

def solution():
    N = int(input())
    K = int(input())
    apples = [[0] * (N+1) for _ in range(N+1)]
    rotations = []
    for _ in range(K):
        r, c = map(int, input().split())
        apples[r][c] = 1
    L = int(input())
    for _ in range(L):
        second, dir = input().split()
        rotations.append((int(second), dir))

    time = 0
    dir = 1
    snake = collections.deque([(1,1)])
    while True:
        time += 1
        nr = snake[0][0] + dr[dir]
        nc = snake[0][1] + dc[dir]
        if nr < 1 or nc < 1 or nr > N or nc > N or (nr, nc) in snake:
            break


        snake.appendleft((nr, nc))
        if apples[nr][nc]:
            apples[nr][nc] = 0
        else:
            snake.pop()

        for rotationDir in [r[1] for r in rotations if r[0] == time]:
            if rotationDir == 'L':
                dir = (dir - 1) % 4
            else:
                dir = (dir + 1) % 4
    return time


print(solution())
