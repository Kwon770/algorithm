"""
https://www.acmicpc.net/problem/2512
2512 예산
Memory: 32140 KB, Time: 64 ms

파라메트릭 서치 냄새가 강한 문제였다. 입력 범위 숫자의 절대적인 숫자가 커보이지 않지만, N*M 복잡도를 생각하면 10억이 넘는다.
이 문제의 경우 워낙 노골적인 파라메트릭 서치 티를 내서 헤매지 않아지만, 다른 문제에서는 범위와 문제 풀이 방식을 유심히 봐야겠다.

!! - 조심할 점은 low를 min(requests)로 단정지으면 절대 안된다. 예산에 따라 0부터 시작해야 할 수도 있는 것이다. !!
- 파이썬은 해당 안되지만, 총액 범위가 크다. 주목만 하자. 
"""""

import sys; readline = sys.stdin.readline

N = int(readline())
requests = list(map(int, readline().split()))
budget = int(readline())
answer = 0

low = 0
high = max(requests)
while low <= high:
    mid = (low + high) // 2
    usage = 0

    for request in requests:
        if mid < request:
            usage += mid
        else:
            usage += request

    if usage <= budget:
        answer = max(answer, mid)
        low = mid + 1
    else:
        high = mid - 1

print(answer)