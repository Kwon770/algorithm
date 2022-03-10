# https://www.acmicpc.net/problem/2696
# 2696 증앙값 구하기
# Memory : 33952 KB / Time : 184 ms

# 가장 단순한 방법은 숫자를 추가할때마다 정렬하고, 인덱스로 중간 값을 구하는 것이다.
# 하지만 이 경우, 1초 제한에 N <= 9999 환경에서 복잡도 O(N^2logN) 으로 시간초과다.

# 정렬이 잦으므로, PriorityQueue(heapq)의 경우 복잡도 O(logN)으로 해결가능하다.
# MinHeap의 heapq 배열의 원소 전부가 오름차순으로 정렬된 것이 아니라 최소힙 트리구조로 저장되므로, 힙 하나 만으로는 중앙값을 구할 수 없다.
# MaxHeap과 MinHeap을 동시에 사용하면 MaxHeap에서 배열 전체의 중간값을 바로 늘 구할 수 있다.
# Max Heap    Max Heap
# [ 1, 2, 3]   [4, 5]

# 1. 초기에는 mxq에 넣는다.
# 2. mxq.size > mnq.size
# 2-1. 값이 중앙값보다 작으면, 중앙값-> mnq, 값 -> mxq
# 2-2. 값이 중앙값보다 크거나 같으면, 값 -> mnq
# 3. mxq.size == mnq.size
# 3-1. 값이 중앙값보다 크면, 값 -> mxq, mxq.top -> mnq [큰 값이 갱신되면, mnq에서 중앙값이 발생하므로 갱신해야됨]
# 3-2. 값이 중앙값보다 작거나 같으면, 값 -> mnq [mxq에서 중앙값이 발생하므로 갱신할 필요 없음]

import sys; readline = sys.stdin.readline
import heapq

class node:
    def __init__(self, num):
        self.num = num

    def __lt__(self, other):
        if self.num <= other.num:
            return True
        else:
            return False

def solution():
    for _ in range(int(readline())):
        M = int(readline())
        arr = []
        while len(arr) < M:
            arr.extend(list(map(int, input().split())))
        max_q = []
        min_q = []

        cnt = 1
        mids = [arr[0]]
        heapq.heappush(max_q, node(-arr[0]))
        for i in range(1, len(arr)):
            n = arr[i]
            if len(max_q) > len(min_q):
                if -max_q[0].num <= n:
                    heapq.heappush(min_q, node(n))
                else:
                    heapq.heappush(min_q, node(-max_q[0].num))
                    heapq.heappop(max_q)
                    heapq.heappush(max_q, node(-n))
            else:
                if -max_q[0].num < n:
                    heapq.heappush(min_q, node(n))
                    heapq.heappush(max_q, node(-min_q[0].num))
                    heapq.heappop(min_q)
                else:
                    heapq.heappush(max_q, node(-n))

            if i % 2 == 0:
                cnt += 1
                mids.append(-max_q[0].num)

        print(cnt)
        for i in range(0, cnt, 10):
            print(*mids[i:i+10], sep=" ")

solution()