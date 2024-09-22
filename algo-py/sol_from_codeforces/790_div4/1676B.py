# https://codeforces.com/contest/1676/problem/B
# B Equal Candies
# Memory : 5408 KB / Time : 93 ms

for _ in range(int(readline())):
    n = int(readline())
    li = list(map(int, readline().split()))

    m = min(li)
    ans = 0
    for ele in li:
        ans += ele - m

    print(ans)