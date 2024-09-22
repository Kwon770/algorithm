// https://www.acmicpc.net/problem/21866
// 21866, 추첨을 통해 커피를 받자
// Memory : 2020 KB
// Time : 0 ms
// 2021 연세대 신입생 프로그래밍 경진대회 A
//
// 단순한 PS

#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> grades = {100, 100, 200, 200, 300, 300, 400, 400, 500};
  vector<int> scores(9);
  for (int i = 0; i < 9; i++) {
    cin >> scores[i];
  }

  int sum = 0;
  for (int i = 0; i < 9; i++) {
    if (scores[i] > grades[i]) {
      cout << "hacker";
      return 0;
    }

    sum += scores[i];

    if (sum >= 100) {
      cout << "draw";
      return 0;
    }
  }

  cout << "none";
  return 0;
}
