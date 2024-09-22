# https://codeforces.com/contest/1678/problem/A?f0a28=1
# A. Tokitsukaze and All Zero Sequnce
# Memory : 5700 KB / Time : 109 ms

# 연산을 통해 모두 0을 만드는 과정의 본질을 알아차리면 간단하게 해결된다.
# 다양한 테케들도 결과적으로는 유사한 과정을 거친다.

import sys; readline = sys.stdin.readline

for _ in range(int(readline())):
    n = int(readline())
    a = list(map(int, readline().split()))

    a.sort()
    if a[0] == 0:
        zeros = 0
        for ele in a:
            if ele != 0:
                break
            zeros += 1

        print(n - zeros)

    else:
        duplicated = False
        for i in range(1, len(a)):
            if a[i - 1] == a[i]:
                duplicated = True
                break

        if duplicated:
            print(n - 1 + 1)
        else:
            print(n - 1 + 2)