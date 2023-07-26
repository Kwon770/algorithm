# https://www.acmicpc.net/problem/15989
# 15989 1, 2, 3 더하기 4
# Memory: 31256 KB, Time: 40 ms
# Memory: 31256 KB, Time: 44 ms

"""
가장 왼쪽자리부터 차례로 그리디하게 채워넣으면 지뢰 수의 최대값을 구할 수 있었다
확정된 지뢰의 위치 때문에 문자열을 통한 시뮬레이션으로 풀었다

지뢰 찾기의 특성을 이용한 풀이도 깔끔했지만, 속도 차이는 거의 없었고 내 풀이가 더 유니버셜해서 체크만했다.
아예 전체 갯수에서 // 3하면 정답이 나오는 풀이도 있었지만, 너무 핵한 풀이인 것 같아서 고려하지 않았다.. 
"""""


import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 5)

def get_mines(i):
    cnt = 0
    for j in [-1, 0, 1]:
        k = i + j
        if k < 0 or k >= m:
            continue

        if ground[k] == '*':
            cnt += 1

    return cnt

def plant_mines(i, cnt):
    global ground, ans

    for j in [-1, 0, 1]:
        k = i + j
        if k < 0 or k >= m:
            continue

        if ground[k] == '#':
            if cnt > 0:
                ground[k] = '*'
                cnt -= 1
            else:
                ground[k] = 'x'


for _ in range(int(readline())):
    m = int(readline())
    spec = list(map(int, readline().rstrip()))
    ground = list(readline().rstrip())

    for i in range(m):
        mines = get_mines(i)
        plant_mines(i, spec[i] - mines)
    print(ground.count('*'))


""" 지뢰찾기 특성을 이용한 깔끔한 풀이
for _ in range(int(readline())):
    m = int(readline())
    spec = list(map(int, readline().rstrip()))
    ground = list(readline().rstrip())

    ans = 0
    for i in range(m):
        if i == 0 and (spec[i] != 0 and spec[i + 1] != 0):
            spec[i] -= 1
            spec[i + 1] -= 1
            ans += 1

        elif i == m - 1 and (spec[i] != 0 and spec[i - 1] != 0
        ):
            spec[i] -= 1
            spec[i - 1] -= 1
            ans += 1

        elif (spec[i - 1] != 0 and spec[i] != 0 and spec[i + 1] != 0):
            spec[i - 1] -= 1
            spec[i] -= 1
            spec[i + 1] -= 1
            ans += 1

    print(ans)
"""