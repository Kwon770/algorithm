// https://www.acmicpc.net/problem/21869
// 21869 Maximub bishop
// Memory : 2156 KB , Time : 0 ms
//
// ...

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define pq priority_queue

int len, n, idx;
list<int> standard, reverseStandard;
list<int> comparison;
bool isSame;

bool compare(list<int>& standard, list<int> comparison) {
    for (int j = 0; j < len; j++) {

        isSame = true;
        int rotation = standard.front() - comparison.front();
        for (auto standardIter = standard.begin(), comparisonIter = comparison.begin();
        standardIter != standard.end(); standardIter++, comparisonIter++) {
            if (*standardIter != *comparisonIter + rotation) {
                isSame = false;
                break;
            }
        }

        if (isSame) {
            return true;
        }

        comparison.push_back(comparison.front());
        comparison.pop_front();
    }

    return false;
}

int reverseNumber(int n) {
    if (n > 2) {
        return n - 2;
    } else {
        return n + 2;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> len;
    for (int j = 0; j < len; j++) {
        cin >> n;
        standard.push_back(n);
        reverseStandard.push_front(reverseNumber(n));
    }
    cin >> idx;

    int ans = 0;
    vector<list<int>> anss;
    for (int i = 0; i < idx; i++) {
        comparison.clear();
        for (int j = 0; j < len; j++) {
            cin >> n;
            comparison.push_back(n);
        }

        if (compare(standard, comparison) || compare(reverseStandard, comparison)) {
            ans++;
            anss.push_back(comparison);
        }
    }

    cout << ans << endl;
    for (auto com : anss) {
        for (auto c : com) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}