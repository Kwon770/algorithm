// https://www.acmicpc.net/problem/1009
// 수학적인 방법과 구현 두 가지 모두로 풀 수 있는 문제
// 1 ~ 10 까지의 숫자의 제곱의 첫 자리 숫자는 반복된다는 수학적 규칙을 이용해서 풀었다.
// 2차원 벡터 (벡터 속 벡터)를 통해 쉽게 접근할 수 있게 사전에 정의하였다.
// 숫자에 따라 인덱스의 예외가 존재하므로, 조심해야 한다.

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<vector<int> > loop = {{1}, {2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6}, {5}, {6}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1}, {10}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, a, b;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        a = (a - 1) % 10;

        int size = loop[a].size();
        if (size == 1) {
            cout << loop[a][0] << endl;
        } else {
            cout << loop[a][b % size == 0 ? size - 1 : b % size - 1] << endl;
        }
    }

    return 0;
}
