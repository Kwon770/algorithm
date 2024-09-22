// https://www.acmicpc.net/problem/2178
// DFS-BFS (5), 미로 탐색
// NUMBER 2178

// DFS BFS, https://www.notion.so/sckwon770/DFS-BFS-6ec22005435048b18669df0f2541538c

// 두 노드의 최단경로를 찾는 문제이므로, BFS를 이용하면 간단히 풀린다.

// 단 BFS 구현 시, 방문한 노드임을 등록하는 코드가 큐에서 노드를 뽑을 때 해선 안된다.
// 그럴 경우, 중복되는 노드가 큐에 들어가 메모리 초과를 일으킬 수 있으므로,
// 큐에 노드를 넣을 때 방문한 노드임을 등록해야 한다.

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

const int MAX = 100 + 1;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int graph[MAX][MAX], visited[MAX][MAX], n, m, mVal = MAX * MAX;

typedef struct {
    int x;
    int y;
    int cnt;
} node;

void bfs() {
    queue<node> Queue;
    Queue.push({1, 1, 1});
    visited[1][1] = true;

    while (!Queue.empty()) {
        node Node = Queue.front();
        Queue.pop();

        if (Node.x == m && Node.y == n) {
            mVal = min(mVal, Node.cnt);
        }

        for (int i = 0; i < 5; i++) {
            int cx = Node.x + dx[i];
            int cy = Node.y + dy[i];
            if (cx > 0 && cx <= m && cy > 0 && cy <= n && graph[cy][cx] && !visited[cy][cx]) {
                Queue.push({cx, cy, Node.cnt + 1});
                visited[cy][cx] = true;
            }
        }
    }
}

int main() {
    memset(visited, 0, sizeof(visited));

    int tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int o = 1; o <= m; o++) {
            while (true) {
                tmp = getchar();
                if (tmp != '\n') break;
            }
            graph[i][o] = tmp - '0';
        }
    }
    bfs();
    cout << mVal << endl;
    return 0;
}