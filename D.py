import sys; readline = sys.stdin.readline
import math

A, B, K = map(int, readline().split())
bigger = max(A, B)
smaller = min(A, B)

if K > 0:
    if bigger > smaller + K:
        print("Frist")
    else:
        print("Second")
elif K < 0:
    print("Frist")