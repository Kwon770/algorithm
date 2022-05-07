#
# 1번
# 성경 지표별 점수를 별도로 관리하고 판단하는 구현 문제

import sys; readline = sys.stdin.readline

def solution(survey, choices):
    scores = dict()
    for t in ['R', 'T', 'C', 'F', 'J', 'M', 'A', 'N']:
        scores[t] = 0
    for i in range(len(survey)):
        if choices[i] == 4:
            continue


        if choices[i] < 4:
            scores[survey[i][0]] += 4 - choices[i]
        else:
            scores[survey[i][1]] += choices[i] - 4

    answer = ''
    if scores['R'] >= scores['T']:
        answer += 'R'
    else:
        answer += 'T'

    if scores['C'] >= scores['F']:
        answer += 'C'
    else:
        answer += 'F'

    if scores['J'] >= scores['M']:
        answer += 'J'
    else:
        answer += 'M'

    if scores['A'] >= scores['N']:
        answer += 'A'
    else:
        answer += 'N'

    return answer