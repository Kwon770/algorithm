// https://www.acmicpc.net/problem/9095
// NUMBER 9095, 1 2 3 더하기

// 메모이제이션을 활용한 dp 문제이다.
// 메모이제이션의 기본값이 문제의 핵심인데,
// " 이 문제는 수가 2개로 이루어진 경우만을 구하므로, 1은 해당수가 아니므로, 2부터 이며 2는 1 + 1, 1가지 경우이다." 이라고 오해할 수 있다.
// 하지만 dp를 통해 메모이제이션 값을 접근하는 경우, 이미 1가지 이상의 숫자가 이루어져 있으며,
// 기반인 수 1 2 3 모두 필요할 수 가 있으므로, 1 2 3 모든 값을 초기에 지정해줘야 하며,
// 1: 1 // 2: 1+1, 2  // 3: 1+1+1, 1+2, 2+1, 3 // 의 값을 가진다.

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

const int ele[3] = {1, 2, 3};
int memo[11];

int dp(int x) {
    if (memo[x] != -1) {
        return memo[x];
    } else {
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            int cx = x - ele[i];
            if (cx <= 0) continue;
            cnt += dp(cx);
        }
        memo[x] = cnt;
        return cnt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp(n) << endl;
    }
    return 0;
}