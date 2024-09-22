// https://www.acmicpc.net/problem/2225
// DP, 2225 합분해

// N인 정수를 K개 뽑는다는 경우의 수는 K의 개수에 따라 DP로 풀 수 있다.
// 0인 정수를 K개를 뽑는다면 경우의 수는 1
// N인 정수를 1개만 뽑는다면 1
// N인 정수를 2개만 뽑는다면 N + 1

// 이 이상의 K의 경우의 수는 dp[n][k] = dp[n - 0][k - 1] + dp[n - 1][k - 1] + ... + dp[n-n][k - 1];
// 와 같은 식으로 k - 1 단계의 경우의 식으로 구할 수 있다.

#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

const int MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= k; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        dp[i][2] = i + 1;
    }

    for (int i = 3; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                if (j - k < 0) continue;

                dp[j][i] += dp[j - k][i - 1];
                dp[j][i] %= MOD;
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}