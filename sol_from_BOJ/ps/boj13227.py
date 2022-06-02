# https://www.acmicpc.net/problem/13227
# 13227 Tic Tae Toe
# Memory : 30840 KB / Time : 68 ms

# 1. 프로그래밍적으로 구현하는 것 VS 일일이 구현하는 것
# 문제의 복잡성과 경우의 수를 종합적으로 판단해서 효율적으로 선택해야 한다.

# 2. 조건문의 효율성과 파이써닉한 구성을 적극 활용해야한다. (등호 3개 연결)

import sys; readline = sys.stdin.readline

pattern = [
    ((0,0), (0,1), (0,2)), ((1,0), (1,1), (1,2)), ((2,0), (2,1), (2,2)),
    ((0,0), (1,0), (2,0)), ((0,1), (1,1), (2,1)), ((0,2), (1,2), (2,2)),
    ((0,0), (1,1), (2,2)), ((0,2), (1,1), (2,0))]

def solve():
    for i in range(len(pattern)):
        p = pattern[i]
        if b[p[0][0]][p[0][1]] != '.' and b[p[0][0]][p[0][1]] == b[p[1][0]][p[1][1]] == b[p[2][0]][p[2][1]]:
            print("YES")
            return

    print("NO")

b = []
for _ in range(3):
    b.append(input())

solve()