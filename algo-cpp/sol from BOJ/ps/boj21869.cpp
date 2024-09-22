// https://www.acmicpc.net/problem/21869
// 21869 Maximub bishop
//
// 비숍의 이동경로가 대각선이라서, 규칙을 찾아서 그에 맞게 다음 비숍을 배치하는
// 등의 풀이는 힘들다고 생각해, dfs 식의 완탐 풀이를 작성하였다.
// !! 하지만, n 이 지나치게 크고, 시간도 1초인점을 주목하여서 완탐을 써서는
// 안됬다..
//
// 이동경로가 대각선이므로, 최대한 배치할려면 최상단에 먼저 배치해야하는 점,
// 그런 배치를 계속하다보면 하단부분에  공간이 생기므로, "최대한 배치"하기위해
// 다시 "최하단에 배치"해야 한다는 규칙을 이용하여 풀어야한다.

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main(void) {

  int n;
  cin >> n;

  if (n == 1)
    cout << 1 << endl;
  else
    cout << 2 * n - 2 << endl;

  for (int i = 1; i <= n; i++) {
    cout << 1 << " " << i << endl;
  }

  for (int i = 2; i <= n - 1; i++) {
    cout << n << " " << i << endl;
  }

  return 0;
}
