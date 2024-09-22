// https://www.acmicpc.net/problem/16438
// 16438 원숭이 스포트

// 지난 번에 푼 석판자르기와 비슷한 느낌이 있어서 핵심을 깨닫는게 비교적 쉬웠다.
// 석판 자르기처럼 분할정복은 아니지만 1차원적인 구현으로는 풀기 어려워보이는
// 점과 문제를 분할할 경우 문제의 조건을 구현하기 쉬워지는 점이 비슷하다. '모든
// 두 원숭이에 대해서 적어도 한번은 적으로 만나도록' 이 부분이 까다로우면서도
// 분할해야한다는 신호인데. 적어도 한번만 적이면 되기 때문에 이미 서로 적으로
// 만난 원숭이에 대해서는 싱경쓰지 않고, 아군이였던 원숭이들끼리 한번 더 편을
// 가르면 해결된다. 처음에 이 풀이르 생각했을 때, 7번의 대진이 강요되는 점
// 때문에 불가능한 풀이라고 생각했는데, 원숭이의 최대 수 99마리가 필요한
// 게임수가 딱 7판이므로, 문제없이 풀이를 적용시킬 수 있다.
//
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

vector<bool> monkey;
int n, cnt = 0;

void print() {
  for (int i = 1; i <= n; i++) {
    if (monkey[i])
      cout << "A";
    else
      cout << "B";
  }
  cout << endl;
}

void solve() {
  int from = 1, to = n, mid;
  queue<pair<int, pair<int, int>>> q;

  q.push({0, {from, to}});
  int prevDepth = 0;
  while (!q.empty()) {
    int depth = q.front().F;
    if (prevDepth != depth) {
      print();
      cnt++;
      prevDepth = depth;
    }

    from = q.front().S.F;
    to = q.front().S.S;
    mid = from + ((to - from) / 2);
    for (int i = from; i <= mid; i++) {
      monkey[i] = true;
    }
    for (int i = mid + 1; i <= to; i++) {
      monkey[i] = false;
    }

    if (from < mid)
      q.push({depth + 1, {from, mid}});
    if (mid + 1 < to)
      q.push({depth + 1, {mid + 1, to}});
    q.pop();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  monkey.resize(n + 1);

  solve();
  for (int i = ++cnt; i <= 7; i++) {
    print();
  }

  return 0;
}
