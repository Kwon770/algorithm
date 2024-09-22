// https://www.acmicpc.net/problem/11049
// Dynamic Programming2 (3), 행렬 곱셈 순서
// NUMBER 11049

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c
// Reference Solution, https://js1jj2sk3.tistory.com/37#recentEntriesß

#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

vector<pair<int, int>> matrix;
int dp[501][501];

int dpf(int tx, int ty) {
    if (tx == ty)
        return dp[tx][ty] = 0;

    if (dp[tx][ty] != 0x3f3f3f3f)
        return dp[tx][ty];

    for (int mid = tx; mid < ty; mid++) {
        int left = dpf(tx, mid);
        int right = dpf(mid + 1, ty);
        dp[tx][ty] = min(dp[tx][ty], left + right + matrix[tx].first * matrix[mid].second * matrix[ty].second);
    }
    return dp[tx][ty];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, h, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h >> v;
        matrix.push_back(make_pair(h, v));
    }
    memset(dp, 0x3f, sizeof(dp));
    cout << dpf(0, n - 1) << endl;
    return 0;
}