# https://www.acmicpc.net/problem/1477
# 1477 휴게소 세우기
# Memory: 32156 KB, Time: 44 ms


"""
이분탐색 심화, 매개변수탐색 (파라매트릭 서치, Parametric search) 문제다.

!! 그리디하게 문제가 접근될 것 같지만 안된다 !!
휴게소 간의 간격을 저장하고 가장 넓은 간격을 매번 휴게소를 설치해서 반토막내면 되지 않을까?
=> 만약 거리 1개에 휴게소를 2개를 설치할 수 있는 경우의 코드 흐름을 생각해보자 => |    1  2 |
    => 최소를 만들 수 없다.

!! 답은 파라매트릭 서치 !!
- 그럼 이렇게 토막난 거리들 어떻게 처리할까?
  - 토막난 거리들 중 어느 거리에 얼마나 휴게소를 설치할지? 휴게소간 거리는 어떻게 할지?
  - 이걸 완전탐색? 불가능에 가깝다고 생각함
- 결국 필요한 것은 '휴게소가 없는 구간의 최대값의 최솟값', 즉 구간의 최댓값보다 넓은 간격은 없다는 뜻
  - 그렇다면 최댓값보다 넓은 구간들은 최댓값을 기준으로 모두 분리시켜 버리면(휴게소 설치) 되지 않을까?
  - 이 '최대값의 최소값'을 구하는과정을 이분탐색 형태로 반복한다
    - 더 이상 탐색할 수 없을때까지, 가능한 값들을 계속 찾으면서 '최대값의 최소값'을 갱신해나간다
  - 그리고 이분탐색 형태로 반복하며 답을 찾는 과정을 파라매트릭 서치 

* 문제 조건에 의하여 spots에 0과 L을 추가했기 때문에, 순회에서 N을 기준으로 하면 안됨
"""""

import sys;

readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N, M, L = map(int, readline().split())
spots = [0, L] + list(map(int, readline().split()))
spots.sort()

start, end = 1, L - 1
ans = 0
while start <= end:
    cnt = 0
    mid = (start + end) // 2
    for i in range(len(spots) - 1):
        if spots[i + 1] - spots[i] > mid:
            cnt += (spots[i + 1] - spots[i] - 1) // mid

    if cnt > M:
        start = mid + 1
    else:
        end = mid - 1
        ans = mid
print(ans)