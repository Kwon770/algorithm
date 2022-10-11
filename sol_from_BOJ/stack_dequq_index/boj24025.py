# https://www.acmicpc.net/problem/24025
# 24025 돌의 정렬 줄세우기
# Memory : 38624 KB / Time : 124 ms

# 문제의 핵심은 어느정도 깨달았지만, PS하기 위한 이해와 실제 PS로 옮기지는 못했다.

# 1. 시야는 요구하는 값의 이하 혹은 이상이기만 하면 된다.
# 시야가 없으면 1, 가리는 것이 없으면 10^9라는 점을 함께 이용해야한다.
# 2. 가장 오른쪽 시야값이 음수인 경우에만 불가능하다.
# 스페셜저지이며, 1번 조건 등의 이유로 그렇다.

# 3. 1 ~ N까지의 서로 다른 키를 가진 N개의 돌의 정령들이다.
# 음수 시야 요구값이 아니면 전부 최대한의 값이기만 하면 될까라는 풀이를 했지만, 조건에서 명시하고있다.

# 4. N <= 7만이므로, O(N^2)으로는 불가하다.
# O(N) 정도로 풀 수 있는 방법은 순차'탐색'뿐이라고 생각하고 풀이를 고민했다.
# 하지만 양수/음수 요구값 모두를 순차탐색을 하면서 탐색 인덱스의 값을 정하는 방식으로는 불가해서, 풀이에 실패했다.

# 그 해답은 스택이였다.
# 결국 양수 요구값은 좌측일수록 높아야하며, 음수 요구값은 본인 우측보다 낮으면 된다.
# 따라서, 오름차순인 순열에서 차례로 front, back에서 하나씩 뽑아서 돌의 정렬 순열을 만든다면,
# 좌측 양수 돌은 우측보다 클 수 밖에 없고, 음수 돌은 양수 돌보다 무조건 작다.

import sys; readline = sys.stdin.readline

n = int(readline())
sights = list(map(int, readline().split()))

stones = [i for i in range(1, n + 1)]
sorted_stones = []

if sights[-1] < 0:
    print(-1)
else:
    front = 0
    back = n - 1
    for s in sights:
        if s > 0:
            sorted_stones.append(stones[back])
            back -= 1
        else:
            sorted_stones.append(stones[front])
            front += 1

    print(*sorted_stones)