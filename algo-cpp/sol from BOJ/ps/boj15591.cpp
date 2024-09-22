// https://www.acmicpc.net/problem/15591
// 15591 Mootube
//
// 두 가지의 함정이 있어서 애를 먹은 문제다.
// 1. 문제는 긴 설명을 통해 연결되지 않은 유사도를 갱신하라는 메시지를 보낸다.
// 입력 마지막의 질문의 요지를 파악하면 유사도를 갱신할 필요가 없음을 알 수 있다. 유사도 갱신은 경로 중에 있는
// 유사도의 최소값을 갱신하게 되는데, 질문에서는 주어주는 유사도보다 큰 유사도 관계의 갯수만 파악하게 된다.
// 즉, 원래의 경로(유사도의 관계)를 통해 접근할 수 있는 동영상과 갱신하여 얻는 동영상의 갯수는 같다.
//
// 2. 유사도 관계를 2차원 벡터에 표시하고, 이를 모두 확인하는 과정을 거치면 TLE가 발생한다.
// if 문과 2차원 배열을 통해 유사도를 확인하게 되면 단순히 반복문의 복잡도가 높아서인지 TLE가 발생한다.
// 따라서 vector를 이용하여 존재하는 유사도만을 가지고 있다가, 존재하는 유사도만을 반복문을 통해 확인해야 한다.

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define pq priority_queue

int N, Q, k, v, cnt = 0;
vector<vector<pair<int, int>>> usado;
vector<bool> visited;
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        visited[cur] = true;

        for (auto connect : usado[cur]) {
            int next = connect.first;
            int usa = connect.second;

            if (visited[next]) {
                continue;
            }

            if (usa >= k) {
                q.push(next);
                cnt++;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    usado.resize(N + 1);
    visited.resize(N + 1, false);
    for (int i = 1; i <= N - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        usado[p].push_back({q, r});
        usado[q].push_back({p, r});
    }

    for (int i = 1; i <= Q; i++) {
        cin >> k >> v;

        q.push(v);
        bfs();
        cout << cnt << endl;

        fill(visited.begin(), visited.end(), false);
        cnt = 0;
    }
    return 0;
}