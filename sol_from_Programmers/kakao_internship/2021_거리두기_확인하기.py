"""
https://school.programmers.co.kr/learn/courses/30/lessons/81302?language=python3#
2021 카카오 채용연계형 인턴쉽 - 거리두기 확인하기

문제 설명과 조건을 복잡하게 설명했지만, 단순화하면 결국 사람과 사람사이의 거리가 2 초과냐 아니냐 계산하는게 핵심이다.
하지만 탐색을 일반적인 BFS로 하지는 않는다.
- 단일 visited를 사용할 경우, 한 사람의 거리 2이하 영역의 방문이 다른 사람의 거리 2이하 영역과 겹치며, 오히려 탐색이 잘못됨
  - 따라서 2차원 visited가 아니라 각 사람을 기준으로 탐색할때마다 방문한 지점을 관리해야 한다
- 거리 2 초과의 탐색은 무의미하다. 탐색의 목적기 결국, 해당 사람 기준으로 거리 두기에 위반되는 거리에 사람이 있냐 없냐 판단 후 있으면 바로 종료인 것이기 때문이다

!! 거리두기 계산 로직상, 탐색 시작 위치는 판단 기준에서 제외 해야 하는데 조건을 바보같지 설정했다 !!
!! 시작점 (x, y)이 아닌 경우에만 판단한다. 단순하게 생각하면 실수할만하다,,, 바본가,, => if (r != x and c != y)  X / if not (r == x and c == y) O !!
"""""

import heapq

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]


def solution(places):
    answer = []

    for place in places:
        result = 1

        row = len(place)
        col = len(place[0])
        for r in range(row):
            for c in range(col):
                if place[r][c] == "X" or place[r][c] == "O":
                    continue

                queue = [(0, r, c)]
                visited = set()
                visited.add((r, c))
                while queue:
                    dist, x, y = heapq.heappop(queue)
                    if not (r == x and c == y) and place[x][y] == "P":
                        result = 0
                        break

                    for i in range(4):
                        nx = x + dr[i]
                        ny = y + dc[i]
                        if nx < 0 or ny < 0 or nx >= row or ny >= col or (nx, ny) in visited or place[x][
                            y] == 'X' or dist == 2:
                            continue

                        heapq.heappush(queue, (dist + 1, nx, ny))
                        visited.add((nx, ny))

                if result == 0: break
            if result == 0: break

        answer.append(result)

    return answer