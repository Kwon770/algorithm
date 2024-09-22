# https://www.acmicpc.net/problem/2096
# 2096 내려가기
# Memory: 31256 KB, Time: 576 ms

"""
평범하게 DP 냄새를 뿌려서 그냥 풀었지만, MLE
풀이를 보고 눈치를 챘다.

메모리 제한이 4MB이다. 
DP를 위해 최대 10,0000(10만)개 * 3줄 * 4MB = 1.2MB의 배열이 입력,최대dp,최소dp 3개를 사용해서 오버된 것으로 보인다.
최대, 최소를 같은 배열을 쓰는대신 2번 계산하는 식으로도 했지만, 메모리 초기화가 제대로 안되는 것인지, 여전히 MLE
내부적인 로직을 위해 메모리가 사용되는데, 이미 아슬아슬한 상태여서 그런듯하다.

!! 정석은 입력부터도 전부를 받는게 아니라, 한 줄을 받을때마다 dp를 계산하는 것이다 !!
DP라고해도 메모리를 포함한 제한 사항을 잘 체크하자.

!! max dp, min dp도 한줄을 쓴다면, 가장 왼쪽 dp를 갱신하고 나면 중간 dp를 계산하는 과정에서 윗줄의 dp가 아니라
방금 갱신한 dp값이 사용되기 때문에 잘못된다 => dp를 두 줄/두 개 가지고 있어야 한다 !!   

여러 겹의 for문 사이에서 두 개의 dp 배열을 다루는데 시간이 조금 걸렸다.
"""""


import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 5)

N = int(readline())
max_dp = list(map(int, readline().split()))
min_dp = max_dp[:]

for i in range(1, N):
    arr = list(map(int, readline().split()))
    new_max_dp = []
    new_min_dp = []

    for j in range(3):
        local_max = -1
        local_min = 9876543210
        for k in [-1, 0, 1]:
            o = j + k
            if o < 0 or o >= 3:
                continue

            if arr[j] + max_dp[o] > local_max:
                local_max = arr[j] + max_dp[o]
            if arr[j] + min_dp[o] < local_min:
                local_min = arr[j] + min_dp[o]

            # print(j, arr[j], local_max, local_min)

        new_max_dp.append(local_max)
        new_min_dp.append(local_min)
    max_dp = new_max_dp[:]
    min_dp = new_min_dp[:]
    # print(max_dp, min_dp)

print(max(max_dp), min(min_dp))