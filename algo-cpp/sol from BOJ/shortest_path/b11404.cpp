// https://www.acmicpc.net/problem/11404
// Shortest path 5, 플로이드
// NUMBER 11404

// 플로이드 와샬 알고리즘을 사용하는 문제
// 플로이드 와샬 알고리즘 정리본, https://www.notion.so/sckwon770/Floyd-Warshall-2bb6020991a14c509390090f668663d7

#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;

#define INF 1000000000
#define N_MAX 100 + 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, dist[N_MAX][N_MAX];
    cin >> N >> M;

    // dist 배열 초기화
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = i == j ? 0 : INF;
        }
    }

    // 간선 정보 압력
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    // 플로이드 와샬 알고리즘
    for (int via = 1; via <= N; via++) {
        for (int from = 1; from <= N; from++) {
            if (dist[from][via] == INF)
                continue;

            for (int to = 1; to <= N; to++) {
                if (dist[via][to] == INF || from == to)
                    continue;

                dist[from][to] = min(dist[from][to], dist[from][via] + dist[via][to]);
            }
        }
    }

    // 출력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INF) {
                cout << 0 << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}