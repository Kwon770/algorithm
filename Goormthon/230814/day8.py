import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

N = int(readline())
ans = 0

ans += N // 14
N %= 14

ans += N // 7
N %= 7

ans += N // 1
print(ans)