import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

ans = 0
for _ in range(int(readline())):
    a, b, c = readline().split()
    a, c = int(a), int(c)
    if b == '+':
        ans += a + c
    elif b == '-':
        ans += a - c
    elif b == '*':
        ans += a * c
    elif b == '/':
        ans += a // c

print(ans)