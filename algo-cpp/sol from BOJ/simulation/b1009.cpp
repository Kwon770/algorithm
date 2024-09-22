// https://www.acmicpc.net/problem/1009
// 수학적인 방법과 구현 두 가지 모두로 풀 수 있는 문제
// 이 풀이는 구현을 이용하였지만, 시간이 오래 걸리는 풀이다.

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, a, b;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        int tmp = 1;
        for (int j = 0; j < b; j++) {
            tmp *= a;
            tmp %= 10;

            if (tmp == 0) {
                tmp = 10;
                break;
            }
        }
        cout << tmp << endl;
    }

    return 0;
}
