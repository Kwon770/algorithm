import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)


N, K = map(int, readline().split())
arr = []
for i in list(map(int, readline().split())):
    arr.append((str(bin(i)).count('1'), i))

arr.sort(reverse = True)
print(arr[K - 1][1])