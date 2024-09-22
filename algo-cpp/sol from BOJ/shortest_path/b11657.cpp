// https://www.acmicpc.net/problem/11657
// Shortest path 4, 타임머신
// NUMBER 11657

// 이 문제는 간선의 가중치가 음수가 있으므로, 다익스트라는 사용이 불가능하며, 벨만 포드 알고리즘을 사용해야 한다.
// 벨만 포드 알고리즘 정리본, https://www.notion.so/sckwon770/Bellman-Ford-Algorithmn-c48141e976dc4dfdbe6d7276673a7499

#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f
// #define INF 987654321
#define MAX 501

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N : Number of Vertex : Number of City
    // M : Number of Edges : Number of Line
    vector<pair<int, int>> edges[MAX];
    int N, M;
    long long dist[MAX];
    memset(dist, 0x3f, sizeof(dist));
    // fill(dist, dist + MAX, INF);
    dist[1] = 0;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        // start city, destination city, time required
        int A, B, C;
        cin >> A >> B >> C;
        edges[A].push_back(make_pair(B, C));
    }

    // (N - 1) + 1 번 루프. 음수사이클 확인을 위해
    bool isCycle = false;
    for (int i = 1; i <= N; i++) {
        // 각 노드를 확인
        for (int j = 1; j <= N; j++) {
            // 노드별 Edge 확인
            for (auto &p : edges[j]) {
                int destination = p.first;
                int time = p.second;
                if (dist[j] != INF && dist[destination] > dist[j] + time) {
                    dist[destination] = dist[j] + time;
                    if (i == N) {
                        // N번째 루프에서 값이 갱신되면 음의 싸이클을 의미함.
                        isCycle = true;
                    }
                }
            }
        }
    }

    if (isCycle)
        cout << -1 << endl;
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF)
                cout << -1 << endl;
            else
                cout << dist[i] << endl;
        }
    }

    return 0;
}