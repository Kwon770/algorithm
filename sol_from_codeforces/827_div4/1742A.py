import sys;

readline = sys.stdin.readline

t = int(readline())
for _ in range(t):
    arr = list(map(int, readline().split()))
    arr.sort()
    if arr[0] + arr[1] == arr[2]:
        print("YES")
    else:
        print("NO")