// https://www.acmicpc.net/problem/15657
// NUMBER 15657, N과 M(8)

// 재귀를 통해 여러 겹의 for문이 돌고 있는 것처럼 구현함.
// idx: 중복 방지를 위한 idx, cnt: 몇 번째 for문인지, str: 쌓는 문자열

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;

int n, m;
vector<int> arr;

void sol(int idx, int cnt, string str) {
    for (int i = idx; i < n; i++) {
        string tmp = str + to_string(arr[i]) + " ";
        if (cnt == m - 1)
            cout << tmp << endl;
        else
            sol(i, cnt + 1, tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int inp;
        cin >> inp;
        arr.push_back(inp);
    }
    sort(arr.begin(), arr.end());
    sol(0, 0, "");

    return 0;
}