#include <iostream>
#include <set>
#define endl "\n"
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int ipt;
    cin >> ipt;
    s.insert(ipt);
  }

  for (auto _s : s) {
    cout << _s << " ";
  }

  return 0;
}
