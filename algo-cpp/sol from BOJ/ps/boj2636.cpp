// https://www.acmicpc.net/problem/2636
// 2636 치즈
// Memory : 2160 KB , Time : 0 ms
//
// 최적화를 위해 부식 치즈의 상하좌우만 확인하면 다음 부식 치즈를 알 수 있다고 생각했지만, 반례가 존재해서 시간이 꽤 많이 걸렸다.
// 그래프가 매 단계 변화하고 변화한 그래프의 외곽만 부식하기 때문에(치즈로 쌓인 빈 공간은 부식되지 않음) 최적화가 전혀 불가능하고,
// 매 단계에 전부 확인해줘야 한다.
// 판의 제일 외각은 치즈가 없다는 것이 헥심이며, 이 부분을 시작으로 매 단계 BFS로 부식 치즈를 찾으면 된다.

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
int row, col, pass = 0;
vector<vector<bool>> plate;
vector<pair<int, int>> showedCheeses;
vector<pair<int, int>> lastCheeses;

void bfs() {
    for (auto cheese : lastCheeses) {
        plate[cheese.first][cheese.second] = false;
    }

    queue<pair<int, int>> queue;
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    queue.push({0, 0});
    visited[0][0] = true;

    while (!queue.empty()) {
        int r = queue.front().first;
        int c = queue.front().second;
        queue.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= row || nc >= col || visited[nr][nc]) {
                continue;
            }

            visited[nr][nc] = true;
            if (plate[nr][nc]) {
                showedCheeses.push_back({nr, nc});
            } else {
                queue.push({nr, nc});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col;
    plate.resize(row, vector<bool>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int inp;
            cin >> inp;
            if (inp == 1) {
                plate[i][j] = true;
            }
        }
    }

    do {
        pass++;
        lastCheeses.clear();
        lastCheeses.assign(showedCheeses.begin(), showedCheeses.end());
        showedCheeses.clear();

        bfs();
    } while (!showedCheeses.empty());

    cout << pass - 1 << endl;
    cout << lastCheeses.size();
    return 0;
}