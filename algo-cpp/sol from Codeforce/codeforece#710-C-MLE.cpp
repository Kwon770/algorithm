#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#define endl "\n"
using namespace std;

#define For(i, j, k) for (int i = j; i < (int)(k); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int ans = INT_MAX;

void bfs(string a, string b) {

  queue<pair<int, pair<string, string>>> q;
  q.push({0, {a, b}});
  while (!q.empty()) {
    pair<int, pair<string, string>> cur = q.front();
    q.pop();

    string ta = cur.S.F, tb = cur.S.S;
    if (ta.compare(tb) == 0) {
      // cout << ta << " " << tb << endl;
      ans = min(ans, cur.F);
      return;
    }

    // cout << ni - 1 << "> " << ta << " " << tb << endl;
    if (sz(ta) == 0 || sz(tb) == 0) {
      ans = min(ans, cur.F + sz(ta) + sz(tb));
      continue;
    }
    int ni = cur.F + 1;
    q.push({ni, {ta.substr(1, sz(ta) - 1), tb}});
    if (sz(ta) > 1)
      q.push({ni, {ta.substr(0, sz(ta) - 1), tb}});
    q.push({ni, {ta, tb.substr(1, sz(tb) - 1)}});
    if (sz(tb) > 1)
      q.push({ni, {ta, tb.substr(0, sz(tb) - 1)}});
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  For(i, 0, t) {
    string a, b;
    cin >> a >> b;

    bfs(a, b);

    cout << ans << endl;
    ans = INT_MAX;
  }

  return 0;
}
