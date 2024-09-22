// https://www.acmicpc.net/problem/10026
// dfs, 10026 적록색약

// dfs 를 통해, 범위를 찾고 색깔을 바꾸는 문제이다.

#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

#define endl "\n"

using namespace std;

int moveI[4] = {0, 1, 0, -1};
int moveJ[4] = {1, 0, -1, 0};
char arr[101][101];
bool visited[101][101];
int n;

void colorDfs(int i, int j, int moved) {
    visited[i][j] = true;

    if (arr[i][j] == 'B')
        return;
    else if (arr[i][j] == 'G')
        arr[i][j] = 'R';

    moved = moved > 1 ? moved - 2 : moved + 2;
    for (int m = 0; m < 4; m++) {
        if (m == moved) continue;

        int nextI = i + moveI[m];
        int nextJ = j + moveJ[m];

        if (nextI < 1 || nextI > n ||
            nextJ < 1 || nextJ > n ||
            visited[nextI][nextJ] || arr[nextI][nextJ] != 'G')
            continue;

        colorDfs(nextI, nextJ, m);
    }
}

void areaDfs(int i, int j, int moved, char color) {
    if (arr[i][j] != color) return;

    visited[i][j] = true;

    moved = moved > 1 ? moved - 2 : moved + 2;
    for (int m = 0; m < 4; m++) {
        if (m == moved) continue;

        int nextI = i + moveI[m];
        int nextJ = j + moveJ[m];

        if (nextI < 1 || nextI > n ||
            nextJ < 1 || nextJ > n ||
            visited[nextI][nextJ])
            continue;

        areaDfs(nextI, nextJ, m, color);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    int areas = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visited[i][j]) continue;

            areas++;
            areaDfs(i, j, -3, arr[i][j]);
        }
    }
    cout << areas << " ";

    memset(&visited[0][0], 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            colorDfs(i, j, -3);
        }
    }

    areas = 0;
    memset(&visited[0][0], 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visited[i][j]) continue;

            areas++;
            areaDfs(i, j, -3, arr[i][j]);
        }
    }
    cout << areas << endl;

    return 0;
}