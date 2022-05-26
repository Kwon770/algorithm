# https://www.acmicpc.net/problem/2023
# 2023 신기한 소수
# Memory : 30840 KB / Time : 72 ms

# 문제의 조건 파악과 정수 다루기 능력을 요구하는 문제였디
# 최대 8자리의 숫자의 소수여부를 확인해야하므로 몇천만 개이므로 아리스토텔레스의 체로 미리
# 캐싱을 하고 확인하는 방법을 생각하게 된다.
# => 하지만 문제의 조건은 매모리를 4MB로 제한하고 있기때문에 미리 캐싱하는 방법을 사용할 수 없다.

# 숫자의 왼쪽부터 N자리가 모두 소수여야하는 조건을 통해 2가지를 알아내야한다.
# 1. 가장 왼쪽 숫자가 소수인 경우부터 뻗어나가므로, 가장 왼쪽이 2/3/5/7인 숫자들 뿐이다.
# 2. 가장 왼쪽부터 N자리가를 확인하는 것이므로, 오른쪽에 숫자를 하나씩 붙여나가는 방식을 사용하면 1번과 함께했을때
#    상당히 많은 경우의 수를 쳐낼 수 있다

# => 일일이 확인하는 방법은 많은 시간이 소요되므로, for문으로 소수를 판별할 때 (2 ~ n ** 0.5) 만큼만 확인하여야 한다.
#    그렇지않으면 시간초과...

import sys; readline = sys.stdin.readline

def isSeive(n):
    if n < 2:
        return False

    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False

    return True

N = int(readline())

cache = [[] for _ in range(N + 1)]
cache[1] = [2, 3, 5, 7]

for i in range(2, N + 1):
    for c in cache[i - 1]:
        for s in range(10):
            num = c * 10 + s
            if isSeive(num):
                cache[i].append(num)

for c in cache[N]:
    print(c)