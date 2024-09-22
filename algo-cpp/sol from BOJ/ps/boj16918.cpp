// https://www.acmicpc.net/problem/16918
// 16918 봄버맨
// Memory : 2288 KB , Time : 36 ms
//
// 어려운 이론이 필요하기보다는 구현할 것이 많은 문제였다.
// 폭탄별로 폭발까지의 시간이 다르다는 것이 복잡도를 높이는 주요한 원인이였는데, 폭발한 폭탄을 찾기위해 모든 칸을 확인하는 과정을
// 필요하다. 이 과정을 줄이기위해 우선순위큐를 떠올렸지만, 폭탄이 폭발하면서 주위의 폭탄을 없애야하는데 해당 좌표의 폭탄을 찾기위해
// 우선순위큐에서 find 하는 과정은 쉽지 않아보였다. 따라서 2차원 벡터에 폭탄이 폭발하는 시간을 저장함으로서 폭탄을 관리하였다.
//
// 한가지 최적화로서, 처음에는 폭탄이 폭발하기까지 남은 시간을 저장하고 1초가 지날때마다 이 시간을 1초씩 뺄려고 했지만,
// 그냥 현재 몇 초인지를 저장하고, 폭탄이 몇 초에 폭발하는지를 저장함으로, 쓸때없는 순회의를 줄일 수 있었다.

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long지

int dR[] = {1, 0, -1, 0};
int dC[] = {0, 1, 0, -1};
int R, C, N, t;
vector<vector<int>> grid;

void plantBombs() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] != -1) {
                continue;
            }

            grid[i][j] = t + 3;
        }
    }
}

void explode(int r, int c) {
    grid[r][c] = -1;

    for (int i = 0; i < 4; i++) {
        int nR = r + dR[i];
        int nC = c + dC[i];
        if (nR < 0 || nC < 0 || nR >= R || nC >= C || grid[nR][nC] == t ) {
            continue;
        }

        grid[nR][nC] = -1;
    }
}

void explodeBombs() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] != t) {
                continue;
            }

            explode(i, j);
        }
    }
}

void changeGrid() {
    if (t % 2 == 0) {
        plantBombs();
    } else {
        explodeBombs();
    }

}

void printGrid() {
    for (auto r : grid) {
        for (auto c : r) {
            if (c == -1) cout << ".";
            else cout << "O";
        }
        cout << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C >> N;
    grid.resize(R, vector<int>(C, -1));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char bomb;
            cin >> bomb;
            if (bomb == 'O') {
                grid[i][j] = 3;
            }
        }
    }

    for (t = 2; t <= N; t++) {
        changeGrid();
    }

    printGrid();

    return 0;
}