// https://www.acmicpc.net/problem/111279
// NUMBER 11279, 최대 힙

#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

vector<int> heap(200002);
int len = 0;

void push(int inp) {
    int idx = len + 1;
    heap[idx] = inp;
    len++;

    while (heap[idx / 2] < heap[idx]) {
        if (idx <= 1) break;

        swap(heap[idx / 2], heap[idx]);
        idx /= 2;
    }
}

void pop() {
    cout << heap[1] << endl;
    heap[1] = 0;

    int idx = 1;
    int parent = 1;
    while (heap[idx * 2] != 0 || heap[idx * 2 + 1] != 0) {
        idx = heap[idx * 2] > heap[idx * 2 + 1] ? idx * 2 : idx * 2 + 1;
        swap(heap[parent], heap[idx]);
        parent = idx;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cmd;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == 0) {
            pop();
        } else {
            push(cmd);
        }
    }

    return 0;
}
