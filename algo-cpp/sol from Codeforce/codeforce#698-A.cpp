// https://codeforces.com/contest/1478/problem/A
// #698 div2 - A. Nezzar and Colorful Balls
//
// 단순한 원리로 풀수있는 그리디 문제다.
// 문제 자체는 단순한데 조건이 독특해서 문제를 이해하는데 시간이 조금 걸렸다.
// 주어지는 공들이 무조건 오름차순이며, 색깔의 종류만 출력하면 되서 풀이가
// 단순해졌다.
//
// 같은 숫저의 공이면 필요한 색깔의 종류를 세아리며, 각 숫자의 공에서 필요한
// 색깔의 수의 최대를 확인하면 된다.
#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  vector<int> ball;
  cin >> t;
  while (t--) {
    cin >> n;

    int idx = n, cnt = 0, maxCnt = 0, prevBall, ball;
    while (idx--) {
      cin >> ball;
      if (idx + 1 == n)
        prevBall = ball;

      if (prevBall == ball) {
        cnt++;
      } else {
        cnt = 1;
      }
      maxCnt = max(cnt, maxCnt);

      prevBall = ball;
    }

    cout << maxCnt << endl;
  }

  return 0;
}
