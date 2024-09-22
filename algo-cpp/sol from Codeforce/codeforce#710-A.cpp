#include <iostream>
#define endl "\n"
using namespace std;

#define For(i, j, k) for (int i = j; i < (int)(k); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  For(i, 0, t) {
    long long n, m, x;
    cin >> n >> m >> x;

    int r = x % n;
    if (r == 0)
      r = n;
    int c = x / n;
    if (r != n)
      c++;

    long long newX = (r - 1) * m + c;
    cout << newX << endl;
  }

  return 0;
}
