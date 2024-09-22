// https://www.acmicpc.net/problem/11066
// Dynamic Programming2 (2), 파일 합치기
// NUMBER 11066

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c
// Solution Notion page, https://www.notion.so/sckwon770/11066-d10ab5528b7b480f964abb83d4377e8b

#include <algorithm>
#include <cstring>
#include <iostream>
#define endl "\n"
using namespace std;

int dp[501][501];
int file[501];
int sum[501];

int dpf(int tx, int ty) {
    if (dp[tx][ty] != 0x3f3f3f3f)
        return dp[tx][ty];

    if (tx == ty)
        return dp[tx][ty] = 0;

    if (tx + 1 == ty)
        return dp[tx][ty] = file[tx] + file[ty];

    for (int mid = tx; mid < ty; mid++) {
        int left = dpf(tx, mid);
        int right = dpf(mid + 1, ty);
        dp[tx][ty] = min(dp[tx][ty], left + right);
    }
    return dp[tx][ty] += sum[ty] - sum[tx - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, k;
    cin >> t;
    while (t--) {
        memset(dp, 0x3f, sizeof(dp));
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> file[i];
            sum[i] = sum[i - 1] + file[i];
        }
        cout << dpf(1, k) << endl;
    }
    return 0;
}