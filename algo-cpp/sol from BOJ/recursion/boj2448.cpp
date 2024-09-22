// https://www.acmicpc.net/problem/2448
// 2448 별 찍기 - 11

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

vector<string> tri = {
    "  *  ",
    " * * ",
    "*****",
};

vector<vector<char>> ans;
int n;

void recursion(int step, int r, int c) {
  if (step == 1) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 5; j++) {
        ans[r + i][c + j] = tri[i][j];
      }
    }
  } else {
    recursion(step / 2, r, c + 3 * step / 2);
    recursion(step / 2, r + 3 * step / 2, c);
    recursion(step / 2, r + 3 * step / 2, c + 3 * step);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  ans.resize(n, vector<char>(5 * (n / 3) + (n / 3 - 1), ' '));
  recursion(n / 3, 0, 0);

  for (auto a : ans) {
    for (auto b : a) {
      cout << b;
    }
    cout << endl;
  }
  return 0;
}
