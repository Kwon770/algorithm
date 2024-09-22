# https://codeforces.com/contest/1675/problem/B
# 1675 B - Make It Increasing
# Memory : 10400 KB / Time : 374 ms

# 주어진 배열을 순회하면서 정렬이 될때까지 주어진 연산(//2) 를 반복한다. (0이 되면 더 이상 연산이 의미 없으므로 탈출)
# 순회가 완료되면 주어진대로 정렬이 완료됬는지 확인하면 된다.

import sys; readline = sys.stdin.readline

T = int(readline())
for _ in range(T):
    n = int(readline())
    li = list(map(int, readline().split()))
    li.append(3000000000)
    li.reverse()

    ans = 0
    for i in range(1, len(li)):
        while li[i - 1] <= li[i]:
            li[i] //= 2
            ans += 1

            if li[i] == 0:
                break

    impossible = False
    for i in range(1, len(li)):
        if li[i - 1] <= li[i]:
            impossible = True

    if impossible:
        print(-1)
    else:
        print(ans)