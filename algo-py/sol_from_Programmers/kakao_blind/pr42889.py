# https://programmers.co.kr/learn/courses/30/lessons/42889
# KAKAO BLIND 실패율

def solution(N, stages):
    answer = []
    fails = [0 for _ in range(N+2)]
    challenges = [0 for _ in range(N+2)]

    for stage in stages:
        fails[stage] += 1
        for i in range(1, stage+1):
            challenges[i] += 1

    failRate = []
    for idx, (fail, challenge) in enumerate(zip(fails, challenges)):
        if idx == 0 or idx == N+1:
            continue

        if challenge == 0:
            failRate.append((0, idx))
            continue

        failRate.append((-(fail / challenge), idx))
    failRate.sort()

    for f in failRate:
        answer.append(f[1])
    return answer