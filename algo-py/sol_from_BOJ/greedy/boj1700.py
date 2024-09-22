# https://www.acmicpc.net/problem/1700
# 1700 멀티탭 스케줄링
# Memory : 30864 KB / Time : 68 ms

# 뽑는 횟수가 최소가 될 콘센트의 위치를 구하는 로직을 깨닫는 것이 핵심이고, 이것을 깨닫는다면 구현 능력에 달렸다.
# 최소의 위치는 (1. 더 이상 등장 안할 기구 2. 가장 나중에 등장하는 기구)의 로직에 따라 구할 수 있고, 이 로직이 그리디의 성격을 가지고 있다.

# 나는 처음 현재 순서 이후에 가장 적게 등장하는 기구를 뽑는 로직을 구상했는데, 반례는 다음과 같다.
# 2 8
# 1 2 3 4 3 4 2 2
# 이 로직은 등장 횟수가 적은 기구가 번갈아가면서 등장할 경우를 감지하지 못하기 때문에 틀렸다.

# 즉, 가장 나중에 등장하는 기구가 다시 등장하기 전까지 영향을 가장 덜 미치는 기구이기 때문이다.

import sys; readline = sys.stdin.readline

def solution():
    N, K = map(int, readline().split())
    seq = list(map(int, readline().split()))

    answer = 0
    tabs = [0 for _ in range(N)]
    for s_idx, s in enumerate(seq):
        if s in tabs:
            continue

        elif 0 in tabs:
            tabs[tabs.index(0)] = s

        else:
            swap_idx = 0
            swap_dist = -1
            for t_idx, t in enumerate(tabs):
                if t not in seq[s_idx:]:
                    swap_idx = t_idx
                    break

                else:
                    dist = seq[s_idx:].index(t)
                    if swap_dist < dist:
                        swap_dist = dist
                        swap_idx = t_idx

            tabs[swap_idx] = s
            answer += 1

    return answer

print(solution())