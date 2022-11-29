# https://codeforces.com/contest/1676/problem/C
# C Most Similar Words
# Memory : 7820 KB / Time : 155 ms

for _ in range(int(readline())):
    n, m = map(int, readline().split())
    li = []
    for _ in range(n):
        li.append(input())

    ans = 9876543210
    for i in range(n):
        for j in range(i + 1, n):
            tmp = 0
            for k in range(m):
                tmp += abs(ord(li[i][k]) - ord(li[j][k]))

            ans = min(ans, tmp)

    print(ans)