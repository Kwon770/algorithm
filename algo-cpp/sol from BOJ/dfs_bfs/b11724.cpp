// https://www.acmicpc.net/problem/11724
// NUMBER 11724, 연결 요소의 개수

// 단순한 DFS 문제이다.
// 시각화하기 쉬운 2차원 데이터가 아니므로, 데이터의 연결관계만 생각하며 푼다.
// 연결 요소의 개수만 구하면 되므로, 일단 연결관계를 확인한 노드는 더이상 필요가 없음을 인지하고 풀면 된다.

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int node[1001][1001], visited[1001], n;

void dfs(int i) {
    for (int o = 1; o <= n; o++) {
        if (node[i][o] && !visited[o]) {
            visited[o] = 1;
            dfs(o);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(node, 0, sizeof(node));
    memset(visited, 0, sizeof(visited));
    int m, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        node[tmp1][tmp2] = 1;
        node[tmp2][tmp1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        else {
            cnt++;
            visited[i] = 1;
            dfs(i);
        }
    }
    cout << cnt << endl;
    return 0;
}