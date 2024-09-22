// https://www.acmicpc.net/problem/7579
// DFS-BFS (7), 토마토 (3차원)
// NUMBER 7579

// DFS BFS, https://www.notion.so/sckwon770/DFS-BFS-6ec22005435048b18669df0f2541538c

// 7576번, 토마토 (2차원)과 똑같은 방식이다.
// https://www.acmicpc.net/problem/7576
// https://github.com/Kwon770/Algorithm/blob/master/boj/DFS-BFS/b7576.cpp

// 다만 토마토가 3차원으로 주어지기 떄문에 BFS의 진행을 3차원으로 진행해야 한다.

#include <algorithm>
#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

typedef struct {
    int x;
    int y;
    int z;
} node;

const int MAX = 100 + 1;
const int dx[] = {0, 0, 1, -1, 0, 0};
const int dy[] = {1, -1, 0, 0, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

int graph[MAX][MAX][MAX],
    n, m, h, cnt = 0;
queue<node> Queue;

void bfs(int p) {
    int prev = p, cur = 0;
    while (!Queue.empty()) {
        node Node = Queue.front();
        Queue.pop();
        cur++;

        for (int i = 0; i < 6; i++) {
            int cx = Node.x + dx[i];
            int cy = Node.y + dy[i];
            int cz = Node.z + dz[i];
            if (cx > 0 && cx <= m && cy > 0 && cy <= n && cz > 0 && cz <= h && graph[cx][cy][cz] == 0) {
                Queue.push({cx, cy, cz});
                graph[cx][cy][cz] = 1;
            }
        }

        if (cur == prev) {
            cnt++;
            cur = 0;
            prev = Queue.size();
        }
    }
}

int main() {
    int initCnt = 0;
    cin >> m >> n >> h;
    for (int u = 1; u <= h; u++) {
        for (int i = 1; i <= n; i++) {
            for (int o = 1; o <= m; o++) {
                cin >> graph[o][i][u];
                if (graph[o][i][u] == 1) {
                    Queue.push({o, i, u});
                    initCnt++;
                };
            }
        }
    }
    bfs(initCnt);
    for (int u = 1; u <= h; u++) {
        for (int i = 1; i <= n; i++) {
            for (int o = 1; o <= m; o++) {
                if (graph[o][i][u] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << cnt - 1 << endl;
    return 0;
}