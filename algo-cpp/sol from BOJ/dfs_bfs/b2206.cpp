// https://www.acmicpc.net/problem/2206
// DFS-BFS (9), 벽 부수고 이동하기
// NUMBER 2206

// DFS BFS, https://www.notion.so/sckwon770/DFS-BFS-6ec22005435048b18669df0f2541538c

// 두 노드의 최단경로를 찾는 문제이므로, BFS를 이용한다.

// 2178번과 거의 흡사한 형태이나, 벽을 부순다는 점이 풀이에 변화를 줘야하게 된다.

// 2178번과 같은 풀이를 하게되면, 벽을 깬 경로와 깨지않은 경로가 같은 노드에서 만났을 때,
// 나머지 한 경로가 더 이상 탐색을 할 수없게 되면서 문제가 발생한다.
// 따라서 단순히 편면의 방문 여부만 확인하는게 아니라, 벽을 깼을 때, 안 깼을 때 모두의 방문 여부를 확인한다.

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

const int MAX = 1000 + 1;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int graph[MAX][MAX], path[MAX][MAX][2], n, m;

typedef struct {
    int x;
    int y;
    int didBreak;
} node;

int bfs() {
    queue<node> Queue;
    Queue.push({1, 1, 0});
    path[1][1][0] = 1;

    while (!Queue.empty()) {
        node Node = Queue.front();
        Queue.pop();
        if (Node.x == m && Node.y == n) return path[Node.x][Node.y][Node.didBreak];

        for (int i = 0; i < 4; i++) {
            int cx = Node.x + dx[i];
            int cy = Node.y + dy[i];

            if (cx > 0 && cx <= m && cy > 0 && cy <= n && !path[cx][cy][Node.didBreak]) {
                if (!graph[cx][cy]) {
                    path[cx][cy][Node.didBreak] = path[Node.x][Node.y][Node.didBreak] + 1;
                    Queue.push({cx, cy, Node.didBreak});
                } else if (graph[cx][cy] && !Node.didBreak) {
                    path[cx][cy][1] = path[Node.x][Node.y][Node.didBreak] + 1;
                    Queue.push({cx, cy, 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    memset(path, 0, sizeof(path));

    int tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int o = 1; o <= m; o++) {
            while (true) {
                tmp = getchar();
                if (tmp != '\n') break;
            }
            graph[o][i] = tmp - '0';
        }
    }
    cout << bfs() << endl;
    return 0;
}