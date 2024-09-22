// https://www.acmicpc.net/problem/1238
// 1238 파티

// 다익 여러번, 벨만 섞어서 최적화 가능한지 내일 기술
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<pair<int, int>>> pathes(m + 1);
    vector<int> dist(n + 1);
    rep1(i, m) {
        int from, to, t;
        cin >> from >> to >> t;
        pathes[from].push_back({t, to});
    }

    vector<int> totalDist(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++) {
        fill(dist.begin(), dist.end(), INT_MAX);
        dist[i] = 0;
        pq.push({0, i});
        while (!pq.empty()) {
            int cur = pq.top().S;
            pq.pop();

            for (auto path : pathes[cur]) {
                int next = path.S;
                int curVal = dist[next];
                int newVal = dist[cur] + path.F;
                if (newVal < curVal) {
                    dist[next] = newVal;
                    pq.push({newVal, next});
                }
            }
        }

        if (i == x) {
            for (int j = 1; j <= n; j++) {
                totalDist[j] += dist[j];
            }
        } else {
            totalDist[i] += dist[x];
        }
    }

    totalDist[x] = -1;
    sort(totalDist.begin(), totalDist.end(), greater<int>());
    cout << totalDist.front();
    return 0;
}
