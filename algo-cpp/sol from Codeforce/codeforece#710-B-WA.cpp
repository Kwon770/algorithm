#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>
#define endl "\n"
using namespace std;

#define For(i, j, k) for (int i = j; i < (int)(k); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

set<int> x;

bool checkXDis(int k) {
  int first = -1, second = -1;
  for (auto iter = x.begin(); iter != x.end(); iter++) {
    if (first == -1) {
      first = *iter;
      iter++;
      if (iter == x.end())
        break;
    }

    second = *iter;
    if (second - first - 1 > k)
      return false;

    first = second;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  For(i, 0, t) {
    x.clear();
    int n, k, ans = 0, last;
    cin >> n >> k;
    string str;
    cin >> str;

    list<int> stars;
    for (int j = 0; j < sz(str); j++) {
      if (str[j] == '*')
        stars.push_back(j);
    }

    if (!stars.empty()) {
      last = stars.front();
      x.insert(stars.front());
      stars.pop_front();
      ans++;
    }
    if (!stars.empty()) {
      x.insert(stars.back());
      stars.pop_back();
      ans++;
    }

    while (!stars.empty()) {
      if (checkXDis(k))
        break;

      auto iter = lower_bound(stars.begin(), stars.end(), last + k + 1);
      if (iter == stars.end())
        iter = stars.begin();
      else {
        if (*iter > last + k + 1)
          iter = lower_bound(stars.begin(), stars.end(), last);
      }

      ans++;
      last = *iter;
      x.insert(*iter);
      stars.erase(iter);
      break;
    }

    cout << ans << endl;
  }

  return 0;
}
