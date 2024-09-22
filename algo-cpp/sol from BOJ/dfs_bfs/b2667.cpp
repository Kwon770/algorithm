// https://www.acmicpc.net/problem/2667
// DFS-BFS (3), 단지번호 붙이기
// NUMBER 2667

// DFS BFS, https://www.notion.so/sckwon770/DFS-BFS-6ec22005435048b18669df0f2541538c

// 단순히 DFS를 시행하는 문제다.

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int graph[26][26], visited[26][26], n;
vector<int> apart;

int dfs(int x, int y) {
    visited[x][y] = 1;
    int cnt = 1;
    for (int i = 0; i < 5; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx > 0 && cx <= n && cy > 0 && cy <= n && graph[cx][cy] && !visited[cx][cy]) {
            cnt += dfs(cx, cy);
        }
    }
    return cnt;
}

int main() {
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++) {
        for (int o = 1; o <= n; o++) {
            while (true) {
                tmp = getchar();
                if (tmp != '\n') break;
            }
            graph[i][o] = tmp - '0';
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int o = 1; o <= n; o++) {
            if (graph[i][o] && !visited[i][o]) {
                apart.push_back(dfs(i, o));
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    sort(apart.begin(), apart.end());
    for (auto iter = apart.begin(); iter != apart.end(); iter++)
        cout << *iter << endl;
    return 0;
}