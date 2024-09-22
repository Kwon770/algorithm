// https://www.acmicpc.net/problem/11286
// Priority Queue(3), 절댓값 힙
// NUMBER 11286

// 최소 힙, 최대 힙의 단순 변형된 힙
// idx, backIdx 는 여러 경우의 수를 확인하기 위한 계산을 하므로, 오버플로어 언더플로우를 방지하여 long long 을 사용해야 함
// Priority Queue, https://www.notion.so/sckwon770/Priority-Queue-f6af9997d8004d648f5ccef59395154e

#include <algorithm>
#include <cstdlib>
#include <iostream>
#define endl "\n"
using namespace std;
int heap[100001];
long long backIdx = 1;

void addHeapElement(int element) {
    heap[backIdx] = element;
    int idx = backIdx;
    backIdx++;
    while (true) {
        if (idx <= 1)
            break;

        if (abs(heap[idx]) < abs(heap[idx / 2])) {
            swap(heap[idx], heap[idx / 2]);
            idx /= 2;
        } else if (abs(heap[idx]) == abs(heap[idx / 2])) {
            if (heap[idx] < heap[idx / 2]) {
                swap(heap[idx], heap[idx / 2]);
                idx /= 2;
            } else {
                break;
            }
        } else {
            break;
        }
    }
}

void deleteHeapElement() {
    if (backIdx == 1) {
        cout << 0 << endl;
        return;
    } else {
        cout << heap[1] << endl;
    }

    heap[1] = heap[backIdx - 1];
    backIdx--;
    int childIdx, heapSize = backIdx - 1;
    long long idx = 1;
    while (true) {
        if (idx * 2 > heapSize)
            break;

        if (idx * 2 + 1 <= heapSize) {
            if (abs(heap[idx * 2]) > abs(heap[idx * 2 + 1])) {
                childIdx = idx * 2 + 1;
            } else if (abs(heap[idx * 2]) < abs(heap[idx * 2 + 1])) {
                childIdx = idx * 2;
            } else {
                if (heap[idx * 2] > heap[idx * 2 + 1]) {
                    childIdx = idx * 2 + 1;
                } else {
                    childIdx = idx * 2;
                }
            }
        }

        if (abs(heap[idx]) > abs(heap[childIdx])) {
            swap(heap[idx], heap[childIdx]);
            idx = childIdx;
        } else if (abs(heap[idx]) == abs(heap[childIdx])) {
            if (heap[idx] > heap[childIdx]) {
                swap(heap[idx], heap[childIdx]);
                idx = childIdx;
            } else {
                break;
            }
        } else {
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    heap[0] = -1;
    int n, temp;
    cin >> n;
    while (n--) {
        cin >> temp;
        if (temp == 0)
            deleteHeapElement();
        else
            addHeapElement(temp);
    }
    return 0;
}