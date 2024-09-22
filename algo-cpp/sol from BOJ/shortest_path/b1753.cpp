// https://www.acmicpc.net/problem/1753
// Shortest path (1), 최단경로
// NUMBER 1753

// 다익스트라 알고리즘을 이용한 문제
// 다익스트라 원리 및 해설은, https://www.notion.so/sckwon770/Dijkstra-s-Algorithm-b37759429525426e9d86368c2e0ac0d6

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define endl "\n"
#define INF 987654321
#define MAX_V 20001
#define MAX_E 300001
using namespace std;
int startNode, V, E;

struct NODE {
    int to;
    int val;
};

// 각 노드의 엣지를 저장하는 벡터
// 0 번 인덱스는 버림
vector<NODE> edges[MAX_E];

// 출발 노드에서부터의 거리
int dist[MAX_V];

void dijkstra() {
    priority_queue<pair<int, int> > pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        // priority_queue 정렬 기준으로 사용되고 있는 pair.first
        // 내림차순 정렬이 기본값이므로, 오름차순 정렬을 위해 -1 을 곱해두었다.
        // int cost = -1 * pq.top().first;
        pq.pop();

        // 현재 노드에서부터 주변에 있는 노드들의 값을 갱신한다.
        int size = edges[cur_node].size();
        for (int i = 0; i < size; i++) {
            // dist는 출발노드로부터의 거리의 최소값
            // val은 출발노드로부터의 계산된 거리값이므로, 현재 노드까지의 거리 + 대상 노드와 현재 노드의 거리
            int new_val = dist[cur_node] + edges[cur_node][i].val;
            int before_val = dist[edges[cur_node][i].to];

            // 현재 노드로부터 연결된 엣지의 목적지까지의 거리와 기존의 거리를 비교하여
            // 새로운 값이 더 작으면 값을 갱신한다.
            if (new_val < before_val) {
                dist[edges[cur_node][i].to] = new_val;
                pq.push({-1 * new_val, edges[cur_node][i].to});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> startNode;

    int from, to, val;
    // 간선 연결
    for (int i = 0; i < E; i++) {
        cin >> from >> to >> val;
        edges[from].push_back(NODE{to, val});
    }

    // 간선 거리 초기화
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
    dist[startNode] = 0;

    dijkstra();

    // 값 출력
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }

    return 0;
}