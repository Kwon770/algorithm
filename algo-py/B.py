import sys; readline = sys.stdin.readline

N, M = map(int, readline().split())
waits = list(map(int, readline().split()))
friends = set(map(int, readline().split()))

ans = 0
moved = 0
for i in range(len(friends)):
    if waits[i] not in friends:
        ans += 1

print(ans)