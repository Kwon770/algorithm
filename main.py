# https://www.acmicpc.net/problem/2583
# 2583 영역 구하기
# Memory : 32412 KB / Time : 104 ms

import sys; readline = sys.stdin.readline
import bisect

for _ in range(int(readline())):
    n, k = map(int, readline().split())
    li = list(map(int, readline().split()))

    li.sort()

    l = -1
    tl = -1
    tl_cnt = 0
    r = -1
    tr = -1
    tr_cnt = 0
    ascn = -1
    ml = -1
    mr = -1
    max_val = -1
    for i in range(n):
        if l != -1 and tr != li[i] and ascn != -1 and ascn != li[i] - 1:
            l = -1
            ascn = -1
            tl_cnt = 0
            tr = -1
            tr_cnt = 0

        if l != -1 and tr != -1 and tr != li[i] and tr_cnt < k:
            l = -1
            ascn = -1
            tl_cnt = 0
            tr = -1
            tr_cnt = 0


        if l == -1:
            if tl != li[i]:
                tl = li[i]
                tl_cnt = 1
            else:
                tl_cnt += 1

            if tl_cnt >= k:
                l = li[i]
                ascn = l

        else:
            if tr != li[i]:
                tr = li[i]
                tr_cnt = 1
            else:
                tr_cnt += 1

            if tr_cnt >= k:
                r = li[i]
                ascn = r

        if l != -1 and r != 1 and max_val < r - l:
            # print("====", l, r)
            max_val = r - l
            mr = r
            ml = l

        # print(i, l, tl, tl_cnt, r, tr, tr_cnt, ascn)



    if max_val == -1:
        print(-1)
    else:
        print(f'{ml} {mr}')
