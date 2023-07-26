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