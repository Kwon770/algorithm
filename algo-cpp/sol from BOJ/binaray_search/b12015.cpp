// https://www.acmicpc.net/problem/12015
// Binaray Search(7), 가장 긴 증가하는 부분 수열 2
// NUMBER 12015

// Binaray Search, https://www.notion.so/sckwon770/Binaray-Search-b50720f0f2df4aa486cf6b3b4797b6d2

// 기존의 가장 긴 증가하는 부분 수열을 푸는 알고리즘으로는 시간복잡도로 인해 시간초과가 나므로.
// 이분 탐색을 사용을 사용해야 함.
// Notion page about 12015, https://www.notion.so/sckwon770/12015-2-40e86bd476684b079cf8b50dc1cedbb4

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, temp;
    cin >> n;
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (lis.empty() || lis.back() < temp) {
            lis.push_back(temp);
        } else {
            auto iter = lower_bound(lis.begin(), lis.end(), temp);
            *iter = temp;
        }
    }
    cout << lis.size() << endl;
    return 0;
}