# https://codeforces.com/contest/1676/problem/E
# E Eating Queries
# Memory : 20523 KB / Time : 1934 ms

# n, q <= 1.5 * 10^5 이므로, 단순히 n^2 복잡도 풀이는 시간초과가 난다.
# 부분합과 이진탐색을 이용하면 간단하게 답을 구하여 출력하게 되는 문제였다.

for _ in range(int(readline())):
    n, q = map(int, readline().split())
    candies = list(map(int, readline().split()))

    s = sum(candies)
    candies.sort(reverse=True)
    cli = []
    tc = 0
    for c in candies:
        tc += c
        cli.append(tc)

    for _ in range(q):
        query = int(input())
        if query > s:
            print(-1)
            continue
        elif query == s:
            print(n)
            continue

        print(bisect.bisect_left(cli, query) + 1)