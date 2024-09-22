# https://programmers.co.kr/learn/courses/30/lessons/60061
# 2020 KAKAO BLUND RECRUITMENT, 기둥과 보 설치

# 거의 다 접근하였지만, 삭제 가능 여부를 확인하는 과정에서 문제가 발생하였다.
# 삭제가 영향을 미치는 건축물 위치의 건축물에 대한 유효성을 확인하는데, 해당 위치에 건출물이 존재하는 경우에만 유효성을 확인해야하는데 존재 여부를 확인 부분을 빠드렸다.

# 본 풀이에서는 시간을 단축하기 위해, 건설과 삭제를 확인하는 부분에서 복잡한 조건을 달았다.
# 하지만, 총 명령의 갯수가 1000개 이하 / 시간 제한 5초 이므로 O(N^3) 까지도 커버 가능하므로, 명령을 수행할때마다 모든 건축물의 유효성을 확인하는 방법을 사용하면
# 더 깔끔하게 코드를 짤수도 있다.
# => pr60061_solution.py

import sys; input = sys.stdin.readline

def isPossibleRemove(x, y, a):
    if a == 0:
        if ([x, y+1, 0] in map and not isPossibleWall(x, y + 1)) or \
                ([x-1, y+1, 1] in map and not isPossibleFloor(x - 1, y + 1)) or \
                ([x, y+1, 1] in map and not isPossibleFloor(x, y + 1)):
            return False

    elif a == 1:
        if ([x-1, y, 1] in map and not isPossibleFloor(x - 1, y)) or \
                ([x+1, y, 1] in map and not isPossibleFloor(x + 1, y)) or \
                ([x, y, 0] in map and not isPossibleWall(x, y)) or \
                ([x+1, y, 0] in map and not isPossibleWall(x + 1, y)):
            return False

    return True


def isPossibleWall(x, y):
    if y == 0:
        return True

    if [x, y - 1, 0] in map:
        return True

    if [x - 1, y, 1] in map:
        return True

    if [x, y, 1] in map:
        return True

    return False

def isPossibleFloor(x, y):
    if [x, y - 1, 0] in map:
        return True

    if [x + 1, y - 1, 0] in map:
        return True

    if [x - 1, y, 1] in map and [x + 1, y, 1] in map:
        return True

    return False

def solution(n, build_frame):
    global map
    map = []

    for task in build_frame:
        x, y, a, b = task
        if b == 0:
            map.remove([x, y, a])
            if not isPossibleRemove(x, y, a):
                map.append([x, y, a])

        elif a == 0 and isPossibleWall(x, y):
            map.append([x, y, a])
        elif a == 1 and isPossibleFloor(x, y):
            map.append([x, y, a])


    map.sort()
    return map

print(solution(5, [[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]))