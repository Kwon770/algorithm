// https://www.acmicpc.net/problem/2606
// DFS-BFS (1), 바이러스
// NUMBER 2606

// DFS BFS, https://www.notion.so/sckwon770/DFS-BFS-6ec22005435048b18669df0f2541538c

#include <cstring>
#include <iostream>
#define endl "\n"
using namespace std;

int graph[101][101], visited[101], num, connection, cnt = 0;

void dfs(int n) {
    for (int i = 1; i <= num; i++) {
        if (graph[n][i] && !visited[i]) {
            cnt++;
            visited[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    cin >> num >> connection;
    int tmp1, tmp2;
    for (int i = 0; i < connection; i++) {
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = 1;
        graph[tmp2][tmp1] = 1;
    }
    visited[1] = 1;
    dfs(1);
    cout << cnt << endl;
    return 0;
}