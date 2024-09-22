// https://www.acmicpc.net/status?user_id=sketom&problem_id=15685&from_mine=1
// 15685 드래곤 커브
//
// 문제의 핵심, 점을 회전하는 법과 회전하는 점을 고르는 규칙을 깨다든 핵심이다.
// 핵심을 깨달으면 구현에는 큰 문제가 없다.
// 1. 공을 시계방향 90도 회전
// 회전을 구현하는 것이 가장 막막하고 어려웠는데, 회전된 점들을 그리고 좌표를
// 관찰하면서 깨달았다. 결국 기준점을 기준을 회전하는 것이기 때문에 회전할 점과
// 기준점의 관계와 기준점과 회전된 점의 관계를 파악해보면 된다. 회전할 점 ->
// 기준점 까지의 x 좌표차를 dx, y 좌표차를 dy라고 명할 경우, 기준점의 x + dy =
// 회전된 점의 x, 기준점의 y + (-dx) = 회전된 점의 y 이다.
// 2. 회전하는 점의 규칙
// 늘 기준점의 마지막점을 제외하고 모드 회전한다. 이를 활용하면 코드로 쉽게
// 구현할 수 있다. 여기선 rbegin() rend() 를 사용했다.
//
#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

#define F first
#define S second

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
int maxRow = -1, maxCol = -1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<bool>> grid(101, vector<bool>(101, false));
  while (n--) {
    int r, c, d, g;
    cin >> c >> r >> d >> g;
    vector<pair<int, int>> dots;
    dots.push_back({r, c});

    for (int i = 0; i <= g; i++) {
      if (dots.size() == 1) {
        dots.push_back({dots[0].F + dr[d], dots[0].S + dc[d]});
      } else {
        pair<int, int> standard = dots.back();
        for (auto iter = dots.rbegin() + 1; iter < dots.rend(); iter++) {
          int row = standard.F - (*iter).F;
          int col = standard.S - (*iter).S;
          dots.push_back({standard.F + (-1 * col), standard.S + row});
        }
      }
    }

    for (auto dot : dots) {
      grid[dot.F][dot.S] = true;
      maxRow = max(maxRow, dot.F);
      maxCol = max(maxCol, dot.S);
    }
  }

  int ans = 0;
  for (int r = 0; r < maxRow; r++) {
    for (int c = 0; c < maxCol; c++) {
      int tmpRow[] = {r, r + 1, r + 1, r};
      int tmpCol[] = {c, c, c + 1, c + 1};
      bool success = true;
      for (int i = 0; i < 4; i++) {
        if (!grid[tmpRow[i]][tmpCol[i]]) {
          success = false;
          break;
        }
      }

      if (success)
        ans++;
    }
  }

  cout << ans;
  return 0;
}
