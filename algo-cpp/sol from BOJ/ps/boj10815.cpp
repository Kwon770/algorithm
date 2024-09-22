#include <algorithm>
#include <iostream>
#include <vector>
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

  int n, m;
  cin >> n;
  vector<int> card(n);
  rep(i, n) { cin >> card[i]; }
  sort(card.begin(), card.end());

  cin >> m;
  rep(i, m) {
    int inp;
    cin >> inp;
    cout << binary_search(card.begin(), card.end(), inp) << " ";
  }

  return 0;
}
