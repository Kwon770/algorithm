# https://programmers.co.kr/learn/courses/30/lessons/60059
# 2020 KAKAO BLUND RECRUITMENT, 자물쇠와 열쇠

# 나는 두 가지의 문제점 때문에 풀지 못하였다
# 1. 2차원 배열을 90도 회전하는 방법을 알아내지 못했다.
# 2. 회전할 수 있는 모든 경우를 확인하는 방법으로써 BFS를 시도하려했다. 구현측면의 기발한 아이디어가 필요하다.

# Sol 1. 90도 회전의 규칙을 담은 rotate_matrix_by_90degree() 함수를 찾았다. 여러 문제에서도 가끔 나오니, 기억해둬야 한다.

# Sol 2. BFS로 모든 경우를 탐색할 경우, 상하좌우 이동 + 시계,반시계 회전을 매 경우의 수마다 뽑아나가서 계산해야한다. 이는 상당히 비효율적이다.
#        """자물쇠 크기의 3배 배열을 만든 다음에, 열쇠를 이동시키면서 확인""" (열쇠를 자물쇠의 여러 위치에서 확인)
# Sol 2-1. 일치하지 않는다면, 90도로 한 번 회전한 다음에 2-1을 다시 시행한다. 이를 총 4번 시행한다.(모든 회전의 경우) (회전했을 때를 확인)
# Sol 2-2. 일치하는 키의 위치인지 확인할려면 자물쇠 위치에 1만 있는지 확인하면 된다. (0 빔. 1 무언가 채워짐. 2 열쇠와 자물쇠가 겹침)

import sys; input = sys.stdin.readline
from collections import deque

def rotate_matrix_by_90degree(a):
    r = len(a)
    c = len(a[0])
    result = [[0] * c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            result[j][r - i - 1] = a[i][j]
    return result

def check(new_lock):
    for r in range(N):
        for c in range(N):
            if new_lock[N + r][N + c] != 1:
                return False

    return True

def solution(key, lock):
    global N, M
    N = len(lock)
    M = len(key)
    new_lock = [[0] * (N * 3) for _ in range(N * 3)]
    for i in range(N):
        for j in range(N):
            new_lock[N+i][N+j] = lock[i][j]

    for rotation in range(4):
        key = rotate_matrix_by_90degree(key)
        for offsetR in range(N * 2):
            for offsetC in range(N * 2):

                for r in range(M):
                    for c in range(M):
                        new_lock[offsetR + r][offsetC + c] += key[r][c]

                if check(new_lock):
                    return True

                for r in range(M):
                    for c in range(M):
                        new_lock[offsetR + r][offsetC + c] -= key[r][c]

    return False



print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]))