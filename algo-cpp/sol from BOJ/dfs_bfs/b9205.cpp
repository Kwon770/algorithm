// https://www.acmicpc.net/problem/9205
// NUMBER 9205, 맥주 마시면서 걸어가기

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;
#define MAX 100 + 2

bool graph[MAX][MAX];
bool visited[MAX];
int n;

// 두 지점간의 거리를 반환
// 맨해튼 거리를 기준으로 계산할 것을 문제에서 요구했다. (x좌표거리 + y좌표거리)
// https://ko.wikipedia.org/wiki/%EB%A7%A8%ED%95%B4%ED%8A%BC_%EA%B1%B0%EB%A6%AC
int dist(pair<int, int> from, pair<int, int> to) {
    return abs(to.first - from.first) + abs(to.second - from.second);
}

// 단순한 dfs
void dfs(int curNode) {
    visited[curNode] = true;
    if (curNode == n + 1) return;

    for (int i = 1; i <= n + 1; i++) {
        if (graph[curNode][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, tX, tY;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));

        cin >> n;
        vector<pair<int, int> > coord;
        for (int j = 0; j < n + 2; j++) {
            cin >> tX >> tY;
            coord.push_back({tX, tY});
        }

        for (int j = 0; j < n + 2; j++) {
            for (int k = j + 1; k < n + 2; k++) {
                if (dist(coord[j], coord[k]) <= 1000) {
                    // 방향이 고려하지 않는 dfs 이므로, 양방향 edges 생성
                    graph[j][k] = true;
                    graph[k][j] = true;
                }
            }
        }

        dfs(0);
        // 마지막 노드를 방문했는지의 여부를 통해 성공여부를 확인한다.
        if (visited[n + 1])
            cout << "happy" << endl;
        else
            cout << "sad" << endl;
    }
    return 0;
}