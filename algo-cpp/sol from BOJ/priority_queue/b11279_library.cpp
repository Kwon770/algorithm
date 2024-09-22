// https://www.acmicpc.net/problem/11279
// Priority Queue(1), 최대 힙
// NUMBER 11279

// 라이브러리 이용
// Priority Queue, https://www.notion.so/sckwon770/Priority-Queue-f6af9997d8004d648f5ccef59395154e

#include <algorithm>
#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int> pq;
    int n, input;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (!input && pq.empty()) {
            cout << 0 << endl;
        } else if (!input) {
            cout << pq.top() << endl;
            pq.pop();
        } else {
            pq.push(input);
        }
    }
    return 0;
}