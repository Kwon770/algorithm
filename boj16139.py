# 중복 질문?
# S*Q 4백만도 상관없지 않나? => 아 서브테스트1까지만 이렇고..
# 이진탐색까지?(으로?) => 중복질문에 대한 이야기는 어캐된거지?

import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
import bisect


S = input()
q = int(input())
dic = dict()
for i in range(len(S)):
    if S[i] in dic:
        dic[S[i]].append(i)
    else:
        dic[S[i]] = [i]

for _ in range(q):
    a, l, r = readline().split()
    l, r = int(l), int(r)

    if not a in dic:
        print(0)
    else:
        left = bisect.bisect_left(dic[a], l)
        right = bisect.bisect_right(dic[a], r)
        print(right - left)