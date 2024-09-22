# https://www.acmicpc.net/problem/10823
# 10823 더하기2
# Memory : 29200 KB / Time : 68 ms

# sys.stdin.read() 을 이용해서 EOF까지 한 번에 입력받는 방법 응용

import sys

nums = [int(num) for num in sys.stdin.read().replace('\n', '').split(',')]
print(sum(nums))