import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

dr = {
    'U': -1,
    'R': 0,
    'D': 1,
    'L': 0
}
dc = {
    'U': 0,
    'R': 1,
    'D': 0,
    'L': -1
}


N = int(readline())
RG, CG = map(int, readline().split())
RP, CP = map(int, readline().split())
arr = []
for _ in range(N):
    arr.append(list(readline().split()))


def get_score(r, c):
    visited = [[False for _ in range(N)] for _ in range(N)]
    score = 0

    while not visited[r][c]:
        count, command = int(arr[r][c][:-1]), arr[r][c][-1]

        for i in range(count):
            if visited[r][c]:
                break

            visited[r][c] = True
            score += 1

            r = (r + dr[command]) % N
            c = (c + dc[command]) % N


    return score


goorm = get_score(RG - 1, CG - 1)
player = get_score(RP - 1, CP - 1)

if goorm > player:
    print('goorm', goorm)
else:
    print('player', player)