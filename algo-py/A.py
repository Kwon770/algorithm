import sys; readline = sys.stdin.readline
import math

scores = {
    "A+": 4.5,
    "A": 4.0,
    "B+": 3.5,
    "B": 3.0,
    "C+": 2.5,
    "C": 2.0,
    "D+": 1.5,
    "D": 1.0,
    "F": 0.0
}

S = readline().rstrip()

total = 0.0
cnt = 0
i = 0
while i < len(S):
    cnt += 1
    if i != len(S) - 1 and S[i + 1] == "+":
        total += scores[S[i:i + 2]]
        i += 1
    else:
        total += scores[S[i]]
    i += 1

print(f'{total / cnt:.5f}')
