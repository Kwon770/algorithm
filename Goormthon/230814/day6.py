import sys; readline = sys.stdin.readline
from itertools import combinations
# sys.setrecursionlimit(10 ** 6)

N = int(readline())
string = readline().rstrip()

cases = [i for i in range(1, N)]
combination = combinations(cases, 2)
all_case = []
parts = set()
for comb in combination:
    case = [string[0:comb[0]], string[comb[0]:comb[1]], string[comb[1]:N]]
    for c in case:
        parts.add(c)
    all_case.append(case)


parts = sorted(list(parts))
scores = dict()
for i in range(1, len(parts) + 1):
    scores[parts[i - 1]] = i


ans = - 1
for case in all_case:
    case_sum = 0
    for c in case:
        case_sum += scores[c]
    ans = max(ans, case_sum)
print(ans)