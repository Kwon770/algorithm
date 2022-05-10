# https://codeforces.com/contest/1676/problem/D
# D X-Sum
# Memory : 8716 KB / Time : 155 ms

# 좌표를 다루는 법, 구현력이 핵심인 문제여서 더 깔끔하게 짤 수 있었을 것 같다.

for _ in range(int(readline())):
    r, c = map(int, readline().split())
    board = []
    for _ in range(r):
        board.append(list(map(int, readline().split())))

    max_val = -1
    for rr in range(r):
        for cc in range(c):
            val = board[rr][cc]

            nr = rr - 1
            nc = cc - 1
            while nr >= 0 and nc >= 0:
                val += board[nr][nc]
                nr -= 1
                nc -= 1

            nr = rr - 1
            nc = cc + 1
            while 0 <= nr < r and 0 <= nc < c:
                val += board[nr][nc]
                nr -= 1
                nc += 1

            nr = rr + 1
            nc = cc + 1
            while nr < r and nc < c:
                val += board[nr][nc]
                nr += 1
                nc += 1

            nr = rr + 1
            nc = cc - 1
            while 0 <= nr < r and 0 <= nc < c:
                val += board[nr][nc]
                nr += 1
                nc -= 1

            max_val = max(max_val, val)
    print(max_val)
