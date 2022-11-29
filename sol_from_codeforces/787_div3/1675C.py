# https://codeforces.com/problemset/problem/1675/C
# 1675 C - Detective Task
# Memory : 9700 KB / Time : 280 ms

# 단순 구현 문제였는데, 영어 독해 실패로 문제를 제대로 이해하지 못했다.
# He asks you to find out the number of those who can be considered a thief according to the answers.
# 도둑으로 ""고려될 수 있는"" 사람의 수를 구하는 것인데, 최소 용의자의 수라고 착각해서 문제를 파악하지 못했다.

# 문제를 이해한다면, 테케에 1만 있는 경우 / 0만 있는 경우 / 모두 있는 경우 / 모두 없는 경우로 분류해서 판별하고
# 마지막 1의 위치, 첫 0의 위치를 통해 분류별로 답을 출력하면 된다.

import sys; readline = sys.stdin.readline

for _ in range(int(readline())):
    s = input()

    if len(s) == 1:
        print(1)
        continue

    non_one = True
    non_zero = True
    last_one = 0
    first_zero = 0

    for i in range(len(s)):
        if s[i] == '1':
            non_one = False
            last_one = i
        elif s[i] == '0':
            if non_zero:
                first_zero = i

            non_zero = False

    if not non_one and not non_zero:
        print(first_zero - last_one + 1)

    elif non_one and not non_zero:
        if first_zero == 0:
            print(1)
        else:
            print(first_zero + 1)

    elif not non_one and non_zero:
        if last_one == len(s) - 1:
            print(1)
        else:
            print(len(s) - last_one)

    else:
        print(len(s))