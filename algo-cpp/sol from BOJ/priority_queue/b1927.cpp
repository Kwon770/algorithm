// https://www.acmicpc.net/problem/1927
// Priority Queue(2), 최소 힙
// NUMBER 1927

// 배열을 이용해 최소 힙 구현
// Priority Queue, https://www.notion.so/sckwon770/Priority-Queue-f6af9997d8004d648f5ccef59395154e

#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;
int heap[100001], backIdx = 1;

void addHeapElement(int element) {
    heap[backIdx] = element;
    int idx = backIdx;
    backIdx++;
    while (true) {
        if (idx <= 1)
            break;

        if (heap[idx] < heap[idx / 2]) {
            swap(heap[idx], heap[idx / 2]);
            idx /= 2;
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
    int childIdx, heapSize = backIdx - 1, idx = 1;
    while (true) {
        if (idx * 2 > heapSize)
            break;

        if (idx * 2 + 1 <= heapSize)
            childIdx = heap[idx * 2] > heap[idx * 2 + 1] ? idx * 2 + 1 : idx * 2;
        else
            childIdx = idx * 2;

        if (heap[idx] > heap[childIdx]) {
            swap(heap[idx], heap[childIdx]);
            idx = childIdx;
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