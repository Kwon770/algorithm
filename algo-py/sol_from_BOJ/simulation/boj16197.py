# https://www.acmicpc.net/problem/16197
# 16197 두 동전
# Memory: 93953 KB, Time: 928 ms
# Memory: 36396 KB, Time: 60 ms

"""
시뮬레이션 문제다. 복잡해질 여지가 있었지만
- 동전끼리는 겹치지 않는다는 점
- 두 동전 중 아무거나 떨어뜨리면 된다던가 하는 점
- 버튼 횟수가 10을 넘어서면 불가능으로 판단한다는 점
으로 인해 BFS 시뮬레이션을 통해 풀 수 있었다. 단 구현할 요소가 많아서 실수하지 않도록 조심해야 했다.

!! list는 stack 이다 !!
간단하게 풀기위해서 list를 통해 BFS의 요소를 push, pop했다.
list는 stack이기 때문에, 버튼 조작 횟수 10 초과부터 종료해야했던 BFS였기 때문에 문제가 발생했다.
- queue, heapq를 사용하자

!! 캐싱을 통해 대폭 최적화할 수 있다 !!
결국 동전이 어디있는지에 대해 모든 경우의 수를 BFS로 탐색하기 때문에, 굉장히 많은 중복이 발생하고 있다.
따라서 이미 탐색한지에 대해 동전의 좌표를 통해 캐싱하고, 이미 탐색한 경우의 수는 큐에 넣지 않는다. 
"""""


import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
import heapq

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

N, M = map(int, readline().split())
coin = [0]
board = []
for i in range(N):
    board.append(input())

    for j in range(M):
        if board[i][j] == 'o':
            coin.append((i, j))

possible = False
q = [coin]
while q:
    coin = heapq.heappop(q)
    if coin[0] >= 10:
        possible = False
        break

    for i in range(4):
        fr = coin[1][0] + dr[i]
        fc = coin[1][1] + dc[i]
        sr = coin[2][0] + dr[i]
        sc = coin[2][1] + dc[i]

        f_drop = False
        f_stop = False
        s_drop = False
        s_stop = False
        if fr < 0 or fc < 0 or fr >= N or fc >= M:
            f_drop = True
        elif board[fr][fc] == '#':
            f_stop = True
            fr = coin[1][0]
            fc = coin[1][1]

        if sr < 0 or sc < 0 or sr >= N or sc >= M:
            s_drop = True
        elif board[sr][sc] == '#':
            s_stop = True
            sr = coin[2][0]
            sc = coin[2][1]

        if (f_drop and not s_drop) or (not f_drop and s_drop):
            print(coin[0] + 1)
            possible = True
            q.clear()
            break
        elif (f_drop and s_drop) or (f_stop and s_stop):
            continue
        else:
            q.append([coin[0] + 1, (fr, fc), (sr, sc)])

if not possible:
    print(-1)