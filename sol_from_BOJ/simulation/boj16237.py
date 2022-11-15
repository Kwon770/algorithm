# https://www.acmicpc.net/problem/16237
# 16237 이삿집센터
# Memory: 30840kb / Time: 72ms

# 문제를 처음 봤을 때는 무게가 짝이 맞는 짐끼리 연산하면 수학적 계산적으로 풀 수 있지않을까?라고 생각이 들지만
# 짝이 될 수 있는 짐이 많아지면서 연산이 복잡해진다.
# 각 짐 갯수의 최대값이 1000인 문제에서 복잡하게 로직을 짜서 수학적으로 푸는 것보다는 시뮬레이션으로 짐 갯수를 확인하는 것이 가성비 좋아보인다.

import sys; readline = sys.stdin.readline

luggage = list(map(int, readline().split()))
answer = luggage[4]

luggage = luggage[:4]
count = sum(luggage)
while count > 0:
    container = 5
    answer += 1
    for i in range(3, -1, -1):
        if container == 0:
            break

        while container >= (i+1):
            if luggage[i] == 0:
                break

            container -= (i+1)
            luggage[i] -= 1
            count -= 1

print(answer)