'''
https://www.acmicpc.net/problem/1987
1987 알파벳

Memory : 48140 KB
Time : 1896 ms

그래프 탐색을 통해 최대값을 확인하면 된다.
단, 함수콜 비용때문인지, DFS 는 어떻게해도 시간초과가 나온다.
'''

dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

def bfs(cr, cc):
    global ans
    q = set([(cr, cc, board[cr][cc])])

    while q:
        cr, cc, alphabets = q.pop()
        if len(alphabets) > ans: ans = len(alphabets)

        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if nr < 0 or nc < 0 or nr >= r or nc >= c:
                continue
            if board[nr][nc] in alphabets:
                continue

            q.add((nr, nc, alphabets + board[nr][nc]))


r, c = map(int, input().split())
board = [list(input()) for _ in range(r)]
ans = 1
bfs(0, 0)
print(ans)