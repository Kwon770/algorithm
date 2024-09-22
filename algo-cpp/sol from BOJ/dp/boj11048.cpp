// https://www.acmicpc.net/problem/11048
// 11048 이동하기
//
// 문제를 처음 봤을 때 직접 모든 경로를 계산하지 않으면 구할 수 없다고 생각되서
// 자연스럽게 경롤를 모두 계산할 수 있는 dfs로 풀었다. 다만 n, m 이 최대
// 1000이라서 TLE가 떴다. 때문에 캐싱을 통해 시간을 줄이기위해 캐싱 + bfs 로
// 풀었으나, 이번엔 대기열 큐의 메모리 초과가 났다. 여기서 다시한번 생각하니
// 문제에서 경로 이동은 우, 하, 우하단 뿐인 것이 포인터였고, 이 뜻은 경로를
// 시뮬레이팅하지 않아고 배열을 순회하면서 계산만하면 된다는 뜻이였다.
// 계산만을 요하는, 순전히 dp 문제였다.
//
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define F first
#define S second

int dr[] = {1, 0, 1};
int dc[] = {0, 1, 1};

int n, m;
vector<vector<int>> maze;
vector<vector<int>> value;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  maze.resize(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> maze[i][j];
    }
  }
  value.resize(n, vector<int>(m, 0));
  value[0][0] = maze[0][0];

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (r + 1 == n && c + 1 == m)
        break;

      for (int k = 0; k < 3; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
          continue;

        value[nr][nc] = max(value[nr][nc], value[r][c] + maze[nr][nc]);
      }
    }
  }

  cout << value[n - 1][m - 1];

  return 0;
}
