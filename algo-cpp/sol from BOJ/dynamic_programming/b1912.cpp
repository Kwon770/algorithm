// https://www.acmicpc.net/problem/1912
// Dynamic Programming (15), 연속합
// NUMBER 1912

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 계속 생길 수 있는 경우를 모두 비교하되 필요없는 연산을 제외하는 식으로 접근해서
// Backtrace를 DP 한 방식으로 푸는 경향이 있음
// 연속된 숫자끼리만 가능하며, 최대값을 구하는 것임을 주목하여 문제의 본질을 파악해야함

// 연속된 숫자끼리 더했을때의 최댓값을 구해야 하므로, 입력받은 수열을 한번 loop 하면서
// 현재 단계 숫자와 현재 단계 숫자 + 이전 단계 숫자의 dp값을 더한 값중에 큰 값을 dp 값에 저장
//   => dp 값은 현재 단계 숫자가 연속된 수열의 마지막 숫자일 경우, 가능한 수열의 합 가운데 최댓값
//   => dp 값은 현재 단계까지의 연속된 수열의 합중 최댓값이므로, 이 값을 더했을때 최댓값이 아니라면
//      현재 단계 이전의 숫자의 어떠한 수열도 이보다 클 수 없으므로 다른 경우를 확인할 필요가 없다

#include <iostream>

using namespace std;
#define MAX 100000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, arr[MAX], dp[MAX], maxVal = -1001;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = arr[0];
    maxVal = max(maxVal, dp[0]);
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        maxVal = max(maxVal, dp[i]);
    }

    cout << maxVal << endl;

    return 0;
}