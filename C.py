import sys; readline = sys.stdin.readline
import math

N, P = map(int, readline().split())
prev = list(map(int, readline().split()))
cur = list(map(int, readline().split()))

pgcd = prev[0]
cgcd = cur[0]
if N > 1:
    pgcd = math.gcd(prev[0], prev[1])
    cgcd = math.gcd(cur[0], cur[1])


for i in range(2, N):
    pgcd = math.gcd(pgcd, prev[i])
    cgcd = math.gcd(cgcd, cur[i])

for i in range(N):
    prev[i] //= pgcd
    cur[i] //= cgcd

max_val = 0
max_idx = 0
for i in range(N):
    value = prev[i] / cur[i]
    if value > max_val:
        max_val = value
        max_idx = i

print(sum(prev), math.floor(sum(cur) * max_val))