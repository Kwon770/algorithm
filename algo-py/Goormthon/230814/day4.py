import sys; readline = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)

N = int(readline())
hambuger = list(map(int, readline().split()))
increase = True
top = -1
broken = False

for i in range(1, N):
    if increase and hambuger[i - 1] > hambuger[i]:
            increase = False
            top = hambuger[i - 1]
    if not increase and hambuger[i - 1] < hambuger[i]:
        broken = True

if broken:
    print(0)
else:
    print(sum(hambuger))