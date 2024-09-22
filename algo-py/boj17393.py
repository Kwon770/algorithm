import sys; readline = sys.stdin.readline
from bisect import bisect_right

N = int(input())
inks = list(map(int, readline().split()))
stinks = list(map(int, readline().split()))

ans = []
for i in range(N):
    end = bisect_right(stinks, inks[i])
    ans.append(end - (i + 1))

print(' '.join(map(str, ans)))
