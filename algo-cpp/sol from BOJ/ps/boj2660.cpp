// https://www.acmicpc.net/problem/2660
// 2660 회장뽑기
// Memory : 2028 KB , Time : 0 ms
//
// 문제를 읽으면 길찾기가 떠오르지만, 문제가 복잡하지 않고 데이터 범위가 작아서 단순 bfs만으로도 충분한 문제다.
// 모든 사람간의 관계의 최대값이 점수이므로, 각 사람마다 bfs를 시작해서 최대값을 저장하면 끝이다.

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int N;
vector<vector<bool>> relation;
vector<int> score;

void solveByBfs(int start) {
    queue<pair<int, int>> queue;
    vector<bool> visited(N, false);

    queue.push({start, 1});
    visited[start] = true;
    while (!queue.empty()) {
        int cur = queue.front().first;
        int step = queue.front().second;
        queue.pop();

        for (int to = 0; to < N; to++) {
            if (!relation[cur][to] || visited[to]) {
                continue;
            }

            score[start] = max(score[start], step);
            visited[to] = true;
            queue.push({to, step + 1});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    relation.resize(N, vector<bool>(N, false));
    score.resize(N, -1);
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) {
            break;
        }

        relation[a - 1][b - 1] = true;
        relation[b - 1][a - 1] = true;
    }

    for (int i = 0; i < N; i++) {
        solveByBfs(i);
    }

    vector<int> candidates;
    int cnt = 0, minScore = *min_element(score.begin(), score.end());
    for (int i = 0; i < N; i++) {
        if (score[i] == minScore) {
            cnt++;
            candidates.push_back(i);
        }
    }
    cout << minScore << " " << cnt << endl;
    for (auto candidate : candidates) {
        cout << candidate + 1 << " ";
    }
    cout << endl;

    return 0;
}