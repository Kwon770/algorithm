// https://www.acmicpc.net/problem/1620
// 1620 나는야 포켓몬 마스터 이다솜

// map을 사용하면 쉽게 풀 수 있음.
// value를 검색하는 함수가 없으므로, map 두 개를 사용한다.

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> nameKey;
    map<int, string> numKey;
    int n, m;
    cin >> n >> m;
    int cnt = 1;
    rep(i, n) {
        string name;
        cin >> name;
        if (nameKey.find(name) == nameKey.end()) {
            nameKey[name] = cnt;
            numKey[cnt] = name;
            cnt++;
        }
    }

    rep(i, m) {
        string inp;
        cin >> inp;
        if (inp[0] < 'A') {
            cout << numKey[stoi(inp)] << endl;
        } else {
            cout << nameKey[inp] << endl;
        }
    }

    return 0;
}