# https://www.acmicpc.net/problem/10775
# 10775 공항
# Memory: 35108 KB, Time: 144 ms, python3

"""
!! 유니온 파인드 !!

1. 비행기가 1 ~ gi의 게이트에만 도킹 가능
2. 도킹이 불가능해지면 즉시 공항 폐쇄
3. 시간 제한 1초
이 3가지 떄문에 단순 탐색과 DP 모두 불가능하게 했다.

1. i보다 작으면서 가장 가까운 숫자를 찾기위해 이분탐색도 고려해봤지만, list는 remove삭제 연산이 N이고, set은 인덱싱이 안되므로 이분탐색이 불가
2. 각 게이트가 도킹해야할 넘버를 가르쳐주는 배열을 사용해볼까라는 아이디어로

비행기 | 게이트 배열
[5]   |  1 2 3 4 5 => 5
[5]   |  1 2 3 4 4 => 4
[5]   |  1 2 3 3 3 => 3  

방식을 떠올려봤지만, 역시나 TLE, 최악의 경우 늘 배열의 최대길이만큼 배열을 확인해야해서인듯하다.

!! 접근 방식은 유사하나, 핵심은 경로 압축이 안되어 있다 !!
!! 유니온 파인드 !!

1. 도킹해야하는 게이트를 찾는 find를 하면서도, 경로 업데이트(압축)
2. 도킹을 완료시키고 나서, 도킹한 게이트를 그 다음 게이트와 union해서 경로 업데이트(압축)

"""""

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

def find(x):
    if gate[x] == x:
        return x

    gate[x] = find(gate[x])
    return gate[x]

def union(x, y):
    x, y = find(x), find(y)
    gate[y] = x

G = int(readline())
gate = [i for i in range(G + 1)]
P = int(readline())
for i in range(P):
    g = int(readline())

    next_gate = find(g)
    if next_gate <= 0:
        P = i
        break

    union(next_gate - 1 , next_gate)

print(P)
