// https://www.acmicpc.net/problem/1012
// DFS-BFS (4), 유기농 배추
// NUMBER 1012

// DFS BFS, https://www.notion.so/sckwon770/DFS-BFS-6ec22005435048b18669df0f2541538c

// 2667번 단지번호 붙이기와 거의 비슷한 DFS다.
// 2667번, https://github.com/Kwon770/Algorithm/blob/master/boj/DFS-BFS/b2667.cpp
// 입력과 출력, 그리고 주어지는 인덱스가 0부터 시작하며,
// 각각의 붙어있는 요소의 개수가 필요없으므로 cnt 변수의 쓰임에 약간의 변형이 필요하다.

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int graph[50][50], visited[50][50], m, n, k;

void dfs(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 5; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx >= 0 && cx < m && cy >= 0 && cy < n && graph[cx][cy] && !visited[cx][cy]) {
            dfs(cx, cy);
        }
    }
}

int solve() {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int o = 0; o < n; o++) {
            if (graph[i][o] && !visited[i][o]) {
                dfs(i, o);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        cin >> m >> n >> k;
        for (int o = 0; o < k; o++) {
            int tx, ty;
            cin >> tx >> ty;
            graph[tx][ty] = 1;
        }

        cout << solve() << endl;
    }
    return 0;
}