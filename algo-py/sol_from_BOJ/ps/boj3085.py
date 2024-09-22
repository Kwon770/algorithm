# https://www.acmicpc.net/problem/3085
# 3085 사탕 게임
# Memory : 30864 KB / Time : 228 ms

# 인접한 사탕의 위치를 변경했을 때의 길이값은 계산할 수 있는 방법은 없어보인다. 즉, 브루트포스 완탐식으로 직접 해봐야한다.
# 단, 브루투포스에 집중하여 모든 사탕을 상하좌우 교체해보고 교체할때마다 사탕을 확인한다면, N <= 50 이더라도 연산양이 어마아마하므로 (N*4*2N^2) TLE 다.
# 1. 모든 사탕을 상하좌우 교체해볼 필요가 없다. 교체는 양방향과 같으므로 중복을 신경써보면 우하 방향만으로도 충분한 것을 알 수 있다.
# 2. 사탕을 교체하면 교체한 위치의 가로세로의 가장 긴 연속 부분의 길이를 확인하면 된다. 굳이 모든 위치의 길이를 확인할 필요가 없다.

import sys; readline = sys.stdin.readline

def getLongestLen(row, col):
    ll = -1
    c = board[row][0]
    l = 0
    for candy in board[row]:
        if c == candy:
            l += 1
        else:
            ll = max(ll, l)
            l = 1
            c = candy
    ll = max(ll, l)

    c = board[0][col]
    l = 0
    for row in board:
        if c == row[col]:
            l += 1
        else:
            ll = max(ll, l)
            l = 1
            c = row[col]
    ll = max(ll, l)

    return ll


dr = [0, 1]
dc = [1, 0]


def solution():
    global N, board
    N = int(readline())
    board = []
    for _ in range(N):
        board.append(list(readline()))

    answer = -1
    for i in range(N):
        answer = max(answer, getLongestLen(i, i))

    for i in range(N):
        for j in range(N):
            for k in range(2):
                nr = i + dr[k]
                nc = j + dc[k]
                if nr < 0 or nc < 0 or nr >= N or nc >= N:
                    continue

                board[i][j], board[nr][nc] = board[nr][nc], board[i][j]
                answer = max(answer, getLongestLen(i, j))
                answer = max(answer, getLongestLen(nr, nc))
                board[i][j], board[nr][nc] = board[nr][nc], board[i][j]

    return answer

print(solution())
