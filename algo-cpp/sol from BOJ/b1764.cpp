// https://www.acmicpc.net/problem/1764
// NUMBER 1764

#include <algorithm>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string tmp;
    vector<string> input(n);
    vector<string> ans;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end());
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (binary_search(input.begin(), input.end(), tmp)) {
            cnt++;
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt << endl;
    for (auto iter = ans.begin(); iter != ans.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}