#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio();
  cin.tie(nullptr);
  cout.tie(nullptr);

  unsigned long long n;
  cin >> n;

  unsigned long long idx = 1, pibo;
  int a = 0, b = 1;
  while (idx++ != n) {
    pibo = a + b;
    pibo %= MOD;
    a = b;
    b = pibo;
  }
  cout << pibo % MOD;

  return 0;
}
