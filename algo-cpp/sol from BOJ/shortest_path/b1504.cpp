// https://www.acmicpc.net/problem/1504
// Shortest path (2), 특정한 최단 경로
// NUMBER 1504

// 다익스트라 알고리즘을 이용한 1753번과 유사한 문제다.
// 다만 다른 점은 중간에 경로 2개가 추가 되었고, 방향성이 없는 그래프이다.

// 수학 시간에 경로 두 점을 거쳐서 최단 경로를 구할때는 점끼리 구별하여 최단 경로를 구한 뒤,
// 구한 최단경로끼리 더하는 방식을 배운 적 있을텐데, 이 문제 또한 같다.
//   1. start > node1 > node2 > end
//   2. start > node2 > node1 > end
// 두 가지의 경로를 각자 구한 뒤, 최소값을 출력하면 된다.

// 다만 여기서 주의해야 할 점은,
//   1. 각 경로를 구할때 나올 수 있는 최대 값은 INF + INF + INF 이므로, 오버플로우가 나는 경우가 있다.]
//      => 불가능한 경로인지 확인할때 INF 이상, 0 미만인지를 확인해야 한다.
//   2. 1752번과 다르게 방향성이 없는 그래프이다.
//      => edge를 추가할 때 양방향으로 추가해야 한다.

#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define endl "\n"
#define INF 987654321
#define MAX_V 801
#define MAX_E 200001
using namespace std;

struct NODE {
    int to;
    int val;
};

// 각 노드의 엣지를 저장하는 벡터
// 0 번 인덱스는 버림
vector<NODE> edges[MAX_E];

array<int, MAX_V> dijkstra(int startNode, int v) {
    // 출발 노드에서부터의 거리
    array<int, MAX_V> dis;
    for (int i = 1; i <= v; i++) {
        dis[i] = INF;
    }
    dis[startNode] = 0;

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
            int new_val = dis[cur_node] + edges[cur_node][i].val;
            int before_val = dis[edges[cur_node][i].to];

            // 현재 노드로부터 연결된 엣지의 목적지까지의 거리와 기존의 거리를 비교하여
            // 새로운 값이 더 작으면 값을 갱신한다.
            if (new_val < before_val) {
                dis[edges[cur_node][i].to] = new_val;
                pq.push({-1 * new_val, edges[cur_node][i].to});
            }
        }
    }
    return dis;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, targetNode1, targetNode2;
    cin >> V >> E;

    // 간선 연결
    int from, to, val;
    for (int i = 0; i < E; i++) {
        cin >> from >> to >> val;
        edges[from].push_back(NODE{to, val});
        edges[to].push_back(NODE{from, val});
    }
    cin >> targetNode1 >> targetNode2;

    array<int, MAX_V> pathFromStart = dijkstra(1, V);
    array<int, MAX_V> pathFromNode1 = dijkstra(targetNode1, V);
    array<int, MAX_V> pathFromNode2 = dijkstra(targetNode2, V);

    int disWithNode1 = pathFromStart[targetNode1] + pathFromNode1[targetNode2] + pathFromNode2[V];
    int disWithNode2 = pathFromStart[targetNode2] + pathFromNode2[targetNode1] + pathFromNode1[V];

    // 값 출력
    if ((disWithNode1 >= INF || disWithNode1 < 0) && (disWithNode2 >= INF || disWithNode2 < 0))
        cout << -1 << endl;
    else if (disWithNode1 < disWithNode2)
        cout << disWithNode1 << endl;
    else
        cout << disWithNode2 << endl;

    return 0;
}