# https://www.acmicpc.net/problem/2852
# 2852 NBA 농구
# Memory: 31256 KB, Time: 40ms

# 시간 계산과 hh:mm 형태의 시간 문자열 다루기에 관한 문제
# 첫 시간과 마지막 시간으로 인한 시간 계산을 예외 처리로 진행햇찌만, 더 깔끔한 방식도 정리해보았다.

# [00:00, Time1, ... ,Time2, 48:00]
# 와 같이 임의로 시간을 추가하면, N + 1개의 간격이 생긴다. 이 간격들을 기준으로 계산한다.
# 빠른 시간 계산을 위해, 시간은 모두 분으로 변환하여 저장해놓는다.


import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

# 시간 간격 초로 계산
# def get_sec(start, end):
#     sec = 0
#     start_h, start_m = map(int, start.split(':'))
#     end_h, end_m = map(int, end.split(':'))
#
#     if start_m <= end_m:
#         sec += end_m - start_m
#     else:
#         sec += 60 + (end_m - start_m)
#         end_h -= 1
#
#     sec += (end_h - start_h) * 60
#
#     return sec
def get_minutes(time):
    h, m = map(int, time.split(':'))
    return m + h * 60

# int 초를 문자열 형태로
def get_format(sec):
    m = str(sec // 60)
    s = str(sec % 60)

    if len(m) == 1:
        m = '0' + m
    if len(s) == 1:
        s = '0' + s

    return m + ":" + s


N = int(input())
one_score = 0 # 득점
two_score = 0
one_win = 0 # 이긴 시간
two_win = 0

# prev_time = '00:00'
# for _ in range(N):
#     team, time = readline().split()
#
#     # 이기고 있던 팀에게 이때까지의 시간 추가, 무승부였다면 시간 변경 없음
#     if one_score < two_score:
#         two_win += get_sec(prev_time, time)
#     elif one_score > two_score:
#         one_win += get_sec(prev_time, time)
#
#     if team == '1':
#         one_score += 1
#     else:
#         two_score += 1
#     prev_time = time
#
# # 남은 시간동안의 시간 계산
# if one_score < two_score:
#     two_win += get_sec(prev_time, '48:00')
# elif one_score > two_score:
#     one_win += get_sec(prev_time, '48:00')
#
# print(get_format(one_win))
# print(get_format(two_win))

arr = []
for _ in range(N):
    team, time = readline().split()
    arr.append((team, get_minutes(time)))
arr.sort(key=lambda x: x[1])

arr.insert(0, ('0', 0)) # 00:00
arr.append(('0', 2880)) # 48:00

for i in range(1, N + 1 + 1):
    if one_score > two_score:
        one_win += arr[i][1] - arr[i - 1][1]
    elif one_score < two_score:
        two_win += arr[i][1] - arr[i - 1][1]

    if arr[i][0] == '1':
        one_score += 1
    else:
        two_score += 1

print(get_format(one_win))
print(get_format(two_win))