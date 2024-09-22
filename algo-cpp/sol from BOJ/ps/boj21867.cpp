// https://www.acmicpc.net/problem/21867
// 21867, Java Bitecode
// 2021 연세대 신입생 프로그래밍 경진대회, B
// Memory : 2648 KB
// Time : 0 ms
//
// String 다루는 문제, 본인은 cpp의 string이 배열처럼 사용될 수 있는 점을
// 이용해서 입력받은 string을 그대로 변형하여 bitecode를 만들고, 그래도
// 출력했다.

#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  string inp;
  cin >> n >> inp;

  int idx = 0;
  for (int i = 0; i < sz(inp); i++) {
    if (inp[i] == 'J' || inp[i] == 'A' || inp[i] == 'V') {
      continue;
    }

    inp[idx] = inp[i];
    idx++;
  }

  if (idx == 0) {
    cout << "nojava";
    return 0;
  }

  for (int i = idx; i < sz(inp); i++) {
    inp[i] = ' ';
  }

  cout << inp;
  return 0;
}
