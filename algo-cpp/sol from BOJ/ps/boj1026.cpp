// https://www.acmicpc.net/problem/1026
// 1026 보물
#include <algorithm>
#include <iostream>
#include <vector>
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

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) { cin >> a[i]; }
  rep(i, n) { cin >> b[i]; }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * b[i];
  }
  cout << ans;

  return 0;
}
