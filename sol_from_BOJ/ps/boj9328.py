# https://www.acmicpc.net/problem/9328
# 9328 열쇠
# Memory: 31256 KB, Time: 196 ms, python3
# Memory: 31256 KB, Time: 256 ms, python3

"""
굉장히 복잡한 구현 문제였다. 
1. 순회가능한 공간인지 아닌지가, 주어진 혹은 찾은 열쇠의 현황에 따라 달라진다는 점
2. 순회하는 중간에 열쇠를 찾으면 다시 순회해야하는 공간이 추가되는 점
3. 열쇠와 문이 알파벳으로 대소문자로 대응된다는 점
등등 구현할 것들도 많고, 실수할 여지가 많으며, 실수하면 구렁텅이에 빠질 여지가 있다.

!! 특히, 열쇠 한 개로 열수있는 문제 1개 이상이다. !!
설명에는 언급이 없고 열쇠와 문이 대응된다는 점 때문에, 테케를 자세히 보지 않으면 오해할 수 있다.

2번 요소 때문에 BFS를 한 번 돌면서 추가적으로 순회해야하는 공간이 생기면 저장해둔다.
한 스탭의 BFS가 끝나면, 한 번 더 순회해야하는지와 어디를 순회해야하는지를 계산한다.
=> AC를 받기는 했지만, 풀이가 복잡하고 여러 번 BFS를 돌아야 했다.
!! => 열쇠의 현황에 따라 변하는 탐색 범위를 어떻게 저장하고, 적절한 타이밍에 큐에 넣는지가 가장 중요하고 풀이를 변화시켰다. !!
!! => 문의 위치를 전처리하여 사용한다는 최적화가 오히려 풀이를 복잡하고 만들었다. !!

다음과 같이 논리를 단순화하면, BFS 1회로 풀이를 완료할 수 있다.
1. 문을 발견했을때
1-1. 키가 있다면, 바로 큐에 넣는다.
1-2. 키가 없다면, 문 목록에 넣는다.
2. 키를 발견했을때, 키를 저장하고 문 목록에 있는 것들을 큐에 전부 넣는다.

!! => 실수를 거듭하다가 풀이가 계속 꼬이는 전형적인 어려운 구현에서 틀리게 되는 시나리오였다. !!
전체적인 논리를 단순화하고 점검하는 습관이 필요할 것 같다.
"""""

import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]


for t in range(int(readline())):
    h, w = map(int, readline().split())
    arr = [list(readline().strip()) for _ in range(h)]
    doors = [[] for _ in range(26)]
    keys = [False] * (26)
    for k in readline().strip():
        # print(k, ord(k) - ord('a'))
        if k == '0':
            continue
        keys[ord(k) - ord('a')] = True

    visited = [[False] * (w) for _ in range(h)]
    ans = 0
    q = []
    for r in [0, h - 1]:
        for c in range(w):
            if arr[r][c] != '*':
                q.append((r, c))
    for c in [0, w - 1]:
        for r in range(1, h - 1):
            if arr[r][c] != '*':
                q.append((r, c))

    while q:
        row, col = q.pop()
        if visited[row][col]:
            continue
        # print(row, col, arr[row][col])

        visited[row][col] = True
        if arr[row][col] != '.':
            if arr[row][col] == '$':
                ans += 1

            elif 'a' <= arr[row][col] <= 'z':
                key_ord = ord(arr[row][col]) - ord('a')
                keys[key_ord] = True
                while doors[key_ord]:
                    q.append(doors[key_ord].pop())
                    visited[q[-1][0]][q[-1][1]] = False

            else:
                door_ord = ord(arr[row][col]) - ord('A')
                if keys[door_ord]:
                    q.append((row, col))
                else:
                    doors[door_ord].append((row, col))
                    continue

        for i in range(4):
            nr = row + dr[i]
            nc = col + dc[i]
            if nr < 0 or nc < 0 or nr >= h or nc >= w or visited[nr][nc] or arr[nr][nc] == '*':
                continue

            q.append((nr, nc))

    print(ans)


# import sys; readline = sys.stdin.readline
# # sys.setrecursionlimit(10 ** 6)
#
# dr = [-1, 0, 1, 0]
# dc = [0, 1, 0, -1]
#
# for t in range(int(readline())):
#     h, w = map(int, readline().split())
#     arr = []
#     doors = dict()
#     for r in range(h):
#         line = list(readline().strip())
#         for c in range(w):
#             if 'A' <= line[c] <= 'Z':
#                 if line[c] in doors: doors[line[c]].append((r, c))
#                 else: doors[line[c]] = [(r, c)]
#
#         arr.append(line)
#     keys = set(readline().strip())
#
#
#     visited = [[False] * (w) for _ in range(h)]
#     ans = 0
#     q = []
#     for r in [0, h - 1]:
#         for c in range(w):
#             if arr[r][c] != '*':
#                 q.append((r, c))
#     for c in [0, w - 1]:
#         for r in range(1, h - 1):
#             if arr[r][c] != '*':
#                 q.append((r, c))
#
#     new_key = ['init']
#     while new_key:
#         # print(new_key)
#         for nk in new_key:
#             if nk.upper() in doors:
#                 for door_r, door_c in doors[nk.upper()]:
#                     if visited[door_r][door_c]:
#                         q.append((door_r, door_c))
#             keys.add(nk)
#         new_key = []
#
#         # print(q)
#         while q:
#             row, col = q.pop()
#             if visited[row][col] and not ('A' <= arr[row][col] <= 'Z'):
#                 continue
#             # print(row, col, arr[row][col])
#
#             visited[row][col] = True
#             if arr[row][col] != '.':
#                 if arr[row][col] == '$':
#                     ans += 1
#
#                 elif 'a' <= arr[row][col] <= 'z':
#                     new_key.append(arr[row][col])
#
#                 else:
#                     if arr[row][col].lower() in keys:
#                         arr[row][col] = '.'
#                     else:
#                         continue
#
#             for i in range(4):
#                 nr = row + dr[i]
#                 nc = col + dc[i]
#                 if nr < 0 or nc < 0 or nr >= h or nc >= w or visited[nr][nc] or arr[nr][nc] == '*':
#                     continue
#
#                 q.append((nr, nc))
#
#     print(ans)