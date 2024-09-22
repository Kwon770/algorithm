# https://www.acmicpc.net/problem/14215
# 14215 세 막대
# Memory: 30840kb / Time: 68ms

# https://way-code.tistory.com/entry/%EB%B0%B1%EC%A4%80-14215%EB%B2%88-%EC%84%B8-%EB%A7%89%EB%8C%80-%ED%8C%8C%EC%9D%B4%EC%8D%AC

import sys; readline = sys.stdin.readline

lines = list(map(int, readline().split()))
lines.sort()
cond = lines[0] + lines[1]
if cond <= lines[2]:
    print(lines[0] + lines[1] + cond - 1)
else:
    print(sum(lines))