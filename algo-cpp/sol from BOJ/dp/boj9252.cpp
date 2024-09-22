// https://www.acmicpc.net/problem/9252
// 9252 LCS2
//
// LCS 알고리즘 + 백트래킹 문제이다
// LCS algorithm : https://www.crocus.co.kr/787
// LCS 알고리즘을 활용하면 쉽게 풀 수 있고, 백트래킹은 LCS 알고리즘의 원리를
// 이용하여 거꾸로 추적하면 된다.
// 1. cache 배열에서 왼쪽, 위쪽 모두 달라서 왼위 대각선에서 + 1을 하는 원리를
// 생각해보면 이때, 현재 LCS에서 문자가 하나 추가되는 경우 이므로 스택에 문자를
// 추가한다.
// 2. 왼쪽 혹은 위쪽의 cache값과 같은 경우, 그대로 cache값을 가져온 것을
// 이용하여 그대로 같은 값의 위치로 인덱스를 움직이면 그대로 역추적하게 된다.
#include <iostream>
#include <stack>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int>> cache(1001, vector<int>(1001, 0));
  string a, b;
  cin >> a >> b;

  for (int i = 1; i <= (int)a.length(); i++) {
    for (int j = 1; j <= (int)b.length(); j++) {
      if (a[i - 1] == b[j - 1]) {
        cache[i][j] = cache[i - 1][j - 1] + 1;
      } else {
        if (cache[i - 1][j] > cache[i][j - 1]) {
          cache[i][j] = cache[i - 1][j];
        } else {
          cache[i][j] = cache[i][j - 1];
        }
      }
    }
  }

  cout << cache[a.length()][b.length()] << endl;

  stack<char> backtrack;
  int r = a.length(), c = b.length();
  while (r != 0 && c != 0) {
    if (cache[r][c] != cache[r - 1][c] && cache[r][c] != cache[r][c - 1]) {
      backtrack.push(a[r - 1]);
      r--;
      c--;
    } else {
      if (cache[r][c] == cache[r - 1][c])
        r--;
      else
        c--;
    }
  }

  while (!backtrack.empty()) {
    cout << backtrack.top();
    backtrack.pop();
  }
  return 0;
}
