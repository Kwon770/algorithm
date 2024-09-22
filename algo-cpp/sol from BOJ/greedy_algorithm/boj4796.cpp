// https://www.acmicpc.net/problem/4796
// 4769 캠핑
//
// 문제가 간단해서 문제 해결을 위한 수식이 간단하게 보인다.
// 수식이 그리디의 원리를 가지고 있다.
//
#include <iostream>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int cnt = 0;
  while (true) {
    int l, p, v;
    cin >> l >> p >> v;
    if (l == 0 && p == 0 && v == 0)
      break;

    cnt++;
    int ans = 0;
    ans += l * (v / p);
    ans += l < (v % p) ? l : v % p;
    cout << "Case " << cnt << ": " << ans << endl;
  }

  return 0;
}
