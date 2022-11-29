# https://codeforces.com/contest/1676/problem/F
# Round #790 F Longest Strike
# Memory : 29400 KB / Time : 280 ms

# 문제의 설명이 핵심을 파악하기 어려웠지만, 그 핵심만 파악한다면 투포인터임을 알 수 있고
# 투포인터의 조건분기를 하다보면 그리디스러움을 알 수 있다.

# 구하라는 것은 r - l 의 최대값이지만, 배열을 정렬할 경우 가장 긴 r과 l을 구하면 되고
# 매번 r을 확장해가며 값을 확인한다. 터무니 없는 값이 나온다면 r과 l을 새로 시작시킨다.

import sys; readline = sys.stdin.readline

def update_max():
    global cnt, k, max_val, arr, r, l, ml, mr

    if cnt >= k and max_val < arr[r] - arr[l]:
        max_val = arr[r] - arr[l]
        ml, mr = l, r

for _ in range(int(readline())):
    n, k = map(int, readline().split())
    arr = list(map(int, readline().split()))
    arr.sort()

    l, r = 0, 0
    ml, mr = 0, 0
    max_val = -1
    num = arr[0]
    cnt = 0
    while r < n:
        if num == arr[r]:
            cnt += 1
            update_max()

            r += 1

        else:
            if num + 1 == arr[r] and cnt >= k:
                num = arr[r]
                cnt = 1
                update_max()

                r += 1

            else:
                num = arr[r]
                cnt = 1

                l = r
                r += 1


    if max_val == -1:
        print(max_val)
    else:
        print(arr[ml], arr[mr])