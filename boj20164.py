import sys; readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

# 홀수 갯수 구하기
def get_odd_cnt(num):
    count = 0
    for n in num:
        if int(n) % 2 != 0:
            count += 1

    return count

def dfs(num, count):
    global N, max_val, min_val
    # 로직이라 ㅇ상관없이 늘 홀수 갯수 계산
    count += get_odd_cnt(num)

    length = len(num)
    # 기저 조건
    if length == 1:
        max_val = max(max_val, count)
        min_val = min(min_val, count)
        return

    elif length == 2:
        new_num = int(num[0]) + int(num[1])
        dfs(str(new_num), count)

    elif length >= 3:
        # 가능한 모든 경우 재귀 (중간 범위의 숫자의 left, right로 자름, slice index 기준)
        for left in range(1, length - 1):
            for right in range(left + 1, length):
                l, m, r = int(num[:left]), int(num[left:right]), int(num[right:])
                new_num = l + m + r
                dfs(str(new_num), count)


N = input()
max_val = -1
min_val = sys.maxsize
dfs(N, 0)
print(min_val, max_val)