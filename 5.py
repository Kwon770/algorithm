import sys; readline = sys.stdin.readline

n = int(readline())
students = []
cache = [[] for _ in range(n + 1)]
for i in range(1, n + 1):
    s, v = map(int, readline().split())
    cache[s].append((i, v))
    students.append((i, v))

taken = [False] * (n + 1)
ans = 0
students.sort(key=lambda x: (-x[1], x[0]))
for s in students:
    me, skill = s[0], s[1]
    if taken[me]:
        continue

    cache[me].sort(key=lambda x: (-x[1], -x[0]))

    for c in cache[me]:
        if not taken[c[0]]:
            ans += skill * c[1]
            taken[me] = True
            taken[c[0]] = True
            break

print(ans)