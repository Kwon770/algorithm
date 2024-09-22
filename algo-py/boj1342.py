# itertools + set = MLE
import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
from itertools import permutations

S = input()
letters = [0] * (26)
ord_a = ord('a')
for s in S:
    letters[ord(s) - ord_a] += 1

ans = 0
def dfs(string, prev, letter):
    global ans
    if len(string) == len(S):
        ans += 1

    for i in range(len(letter)):
        if letter[i] == 0 or prev == i:
            continue

        letter[i] -= 1
        dfs(string + S[i], i, letter)
        letter[i] += 1

dfs('', -1, letters)
print(ans)

# def isLucky(string):
#     for i in range(1, len(string) - 1):
#         if string[i - 1] == string[i] or string[i] == string[i + 1]:
#             return False
#     return True
#
# S = input()
# check = set()
# count = 0
# for p in permutations(S, len(S)):
#     if isLucky(p) and not p in check:
#         check.add(p)
#         count += 1
# print(count)