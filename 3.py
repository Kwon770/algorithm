N = int(input())  # 100000 / 1000000
flours = list(map(int, input().split()))

ans = 0
for i in range(2, max(flours) + 1):
    s = flours[0] % i
    wrong = False
    for f in flours:
        if s != f % i:
            wrong = True
            break

    if not wrong:
        ans += 1

print(ans)