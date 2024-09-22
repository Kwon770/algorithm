// https://www.acmicpc.net/problem/1520
// Dynamic Programming2 (4), 내리막길
// NUMBER 1520

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c
// 처음에는 TLE가 예상되지만 확인차 dfs를 이용한 재귀만으로 풀었다, dp와 메모이제이션을 이용한 해설을 떠올림
// 다만 코드 구현의 부족으로 해답을 봄. [x][y+1] [x][y-1] [x+1][y] [x-1][y] 를 반복을 통해 구현하지 못하여서 해결못함.

// 그 외에 조심해야할 부분은 dp를 -1로 초기화하여 아직 확인하지 못한 부분을 표기하고,
// 확인하는 과정에서 0으로 선언한다. 이로써 조건을 충족하지 못하면 값을 더하지 않아 0으로 남겨두고, 충족할경우 값을 더한다.
// 값을 더하였으면, 충족하므로 반환하여 사용할때마다 값이 더해지고
// 더하지 않았으면, 충족하지 않으므로 반환한다 하더라도 값이 0이므로 결과에 영향을 주지 않음.

#include <algorithm>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int m, n;
int map[501][501], dp[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int dpf(int x, int y) {
    if (x == n && y == m) {
        return 1;
    }

    if (dp[x][y] == -1) {
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && map[x][y] > map[nx][ny]) {
                dp[x][y] += dpf(nx, ny);
            }
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for (int o = 1; o <= m; o++) {
        for (int i = 1; i <= n; i++) {
            cin >> map[i][o];
            dp[i][o] = -1;
        }
    }
    cout << dpf(1, 1) << endl;
    return 0;
}