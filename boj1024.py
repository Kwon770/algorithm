import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N, L = map(int, readline().split())

ans = []
for i in range(L, 101):
    if i % 2 == 0:
        if (N / i) - (N // i) == 0.5:
            ans = [(N // i) - (i // 2) + 1 + j for j in range(i)]
            break

    else:
        if N % i == 0:
            ans = [(N // i) - (i // 2) + j for j in range(i)]
            break

if len(ans) == 0 or ans[0] < 0:
    print(-1)
else:
    print(" ".join(map(str, ans)))