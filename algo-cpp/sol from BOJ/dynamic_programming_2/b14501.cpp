// https://www.acmicpc.net/problem/14501
// NUMBER 14501, 퇴사

#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> time(16);
    vector<int> pay(16);
    vector<int> dp(16);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> time[i] >> pay[i];
    }

    // 역순으로 확인해야 dp를 갱신하며 풀 수 있음
    for (int i = n; i >= 1; i--) {
        // 이 상담을 할만한 충분한 시간이 없을 경우
        if (time[i] > n - i + 1) {
            dp[i] = dp[i + 1];
            continue;
        }

        // 이 상담을 하는 것이 이전 단계의 최대보다 큰 경우
        if (pay[i] + dp[i + time[i]] > dp[i + 1]) {
            dp[i] = pay[i] + dp[i + time[i]];
        } else {
            // 최대의 갱신을 해야함.
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1] << endl;
    return 0;
}