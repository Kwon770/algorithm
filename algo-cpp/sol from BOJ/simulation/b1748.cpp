// https://www.acmicpc.net/problem/1748
// 1748 수 이어 쓰기 1
//
// 주어지는 수의 범위가 크고 0.15초 제한인 것으로 보아, 일일히 세면 무조건 TLE가
// 뜰 것이다. 각 숫자가 그대로 들어가고 그 자릿수를 구하라는 문제이기 때문에
// 단순히 수의 범위를 이용해여 수의 자릿수를 계산해나가면 된다.
//
#include <iostream>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  long long ans = 0;
  int compareStart = 1, compareLast = 9, len = 1;
  while (compareLast <= n) {
    ans += (compareLast - compareStart + 1) * len;
    compareStart *= 10;
    compareLast = compareLast * 10 + 9;
    len++;
  }
  compareLast = compareLast / 10 + 1;
  ans += (n - compareLast + 1) * len;

  cout << ans;
  return 0;
}
