// https://www.acmicpc.net/problem/1655
// Priority Queue(4), 가운데를 말해요
// NUMBER 1655

// Priority Queue, https://www.notion.so/sckwon770/Priority-Queue-f6af9997d8004d648f5ccef59395154e
// 1655 Solution, https://www.notion.so/sckwon770/1655-9bac446434804659a3c4874fc0221334

#include <algorithm>
#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n, temp;
    cin >> n;
    while (n--) {
        cin >> temp;
        if (max_heap.empty()) {
            max_heap.push(temp);
        } else if (max_heap.size() == min_heap.size()) {
            max_heap.push(temp);
        } else {
            min_heap.push(temp);
        }

        if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
            int t = max_heap.top();
            max_heap.pop();
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(t);
        }

        cout << max_heap.top() << endl;
    }
    return 0;
}