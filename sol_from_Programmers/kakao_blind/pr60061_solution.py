import sys; input = sys.stdin.readline

def isPossible(map):
    for x, y, stuff in map:
        if stuff == 0:
            if y == 0 or [x-1, y, 1] in map or [x, y, 1] in map or [x, y-1, 0] in map:
                continue
            return False

        elif stuff == 1:
            if [x, y-1, 0] in map or [x+1, y-1, 0] in map or ([x-1, y, 1] in map and [x+1, y, 1] in map):
                continue
            return False
    return True

def solution(n, build_frame):
    global map
    map = []

    for task in build_frame:
        x, y, stuff, oper = task
        if oper == 0:
            map.remove([x, y, stuff])
            if not isPossible(map):
                map.append([x, y, stuff])

        else:
            map.append([x, y, stuff])
            if not isPossible(map):
                map.remove([x, y, stuff])


    return sorted(map)

print(solution(5, [[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]))