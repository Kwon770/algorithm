// https://www.acmicpc.net/problem/14003
// DP and Shortest path reverse tracking(3), 14003 가장 긴 증가하는 부분 수열 5

// 노션 정리, https://www.notion.so/sckwon770/14003-5-c9f49ef4301f4e23ba17fef29125f7c3

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> inp(n);
    vector<pair<int, int>> arr(n);
    vector<int> sorted;
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }

    sorted.push_back(inp[0]);
    arr[0] = make_pair(0, inp[0]);
    int lis = 1;
    for (int i = 1; i < n; i++) {
        if (sorted.back() < inp[i]) {
            arr[i] = make_pair(sorted.size(), inp[i]);
            sorted.push_back(inp[i]);
            lis++;
        } else {
            int idx = lower_bound(sorted.begin(), sorted.end(), inp[i]) - sorted.begin();
            arr[i] = make_pair(idx, inp[i]);
            sorted[idx] = inp[i];
        }
    }

    vector<int> output;
    int idx = lis - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i].first == idx) {
            output.push_back(arr[i].second);
            idx--;
        }
    }

    cout << lis << endl;
    while (!output.empty()) {
        cout << output.back() << " ";
        output.pop_back();
    }

    return 0;
}