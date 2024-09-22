// https://www.acmicpc.net/problem/9375
// math3(9), 연속합
// NUMBER 9375

// Math Theorem, https://www.notion.so/sckwon770/Math-Theorem-6a3043ed872b41b88fbbafaddbde2fc2

// 다른 특별한 수학적 계산이나 기술없이 패턴을 통한 공식화가 핵심
// (종류 당 의상 개수 + 1) * (종류 당 의상 개수 + 1) * ... * (종류 당 의상 개수 + 1) - 1

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(int n) {
    string wear, kind;
    vector<string> vec;
    int kinds[30];

    vec.clear();
    fill(kinds, kinds + 30, 0);
    for (int i = 0; i < n; i++) {
        cin >> wear >> kind;
        vector<string>::iterator iter = find(vec.begin(), vec.end(), kind);
        if (iter != vec.end()) {
            kinds[distance(vec.begin(), iter)]++;
        } else {
            kinds[vec.size()]++;
            vec.push_back(kind);
        }
    }

    int calculation = 1;
    for (int i = 0; kinds[i]; i++)
        calculation = calculation * (kinds[i] + 1);
    cout << calculation - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        solve(n);
    }

    return 0;
}