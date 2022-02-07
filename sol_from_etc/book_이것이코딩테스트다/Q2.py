# Greedy - Q2 곱하기 혹은 더하기 (P312)

import sys
input = sys.stdin.readline

def solution():
    inp = input()
    ans = int(inp[0])
    for i in range(1, len(inp)-1):
        num = int(inp[i])
        if ans == 0 or num == 0 or ans == 1 or num == 1:
            ans += num
        else:
            ans *= num
    return ans

print(solution())