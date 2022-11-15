# Greedy - Q1 : 모험가 길드 (P311)

import sys
input = sys.stdin.readline

def solution():
    n = int(input())
    scares = list(map(int, input().split()))
    scares.sort()

    ans = 0
    party_scare = 0
    party_count = 0
    for i in range(n):
        party_scare = scares[i]
        party_count += 1

        if party_count >= party_scare:
           ans += 1
           party_count = 0

    return ans

print(solution())