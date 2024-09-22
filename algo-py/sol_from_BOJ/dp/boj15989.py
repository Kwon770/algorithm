# https://www.acmicpc.net/problem/15989
# 15989 1, 2, 3 더하기 4
# Memory: 31256 KB, Time: 48 ms

"""
조합을 이용한 풀이라고 생각하고 직접 구현하려다가 실패했다. 디피인걸 알았어도 못 풀었을 것 같다.

선택지가 1,2,3이므로, 1만으로 이루어진 합 조합에서, 2를 넣을 경우 1 두 개를 빼면 된다는 조합의 규칙을 이용한다.
- 모든 정수 n을 1만 써서 구할 수 있다는 dp
n  |  경우의 수
0    (none)
1    1
2    1+1
3    1+1+1
4    1+1+1+1
- 2를 사용하는 경우의수를 추가하는 dp
n  |  경우의 수
0    (none)
1    1
2    1+1, (none)+2
3    1+1+1, 1+2
4    1+1+1+1, [1+1+2, (none)+2+2]

- 즉, 2를 이용한 경우의 수 dp는 (n - 2)를 1의 합 만으로 나타내는 각 방법에 2를 더한 것이므로
    - { [2를 이용한 (n=4)의 경우의 수] = [1를 이용한 (n=4)의 경우의 수] + [1를 이용한 (n=2)의 경우의 수] } 이다.

"""""

import sys;

readline = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)

dp = [1] * 10001

for i in range(2, 10001):
    dp[i] += dp[i - 2]

for i in range(3, 10001):
    dp[i] += dp[i - 3]

for _ in range(int(readline())):
    n = int(readline())
    print(dp[n])