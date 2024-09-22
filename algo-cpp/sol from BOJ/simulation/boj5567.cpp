// https://www.acmicpc.net/problem/5567
// 5567 결혼식
//
// 그래프 탐색의 느낌이 있지만, 단순한 구현 문제에 가깝다.
// 탐색 범위가 친구의 친구까지라 bfs 까지도 필요 없다.
//
#include <iostream>
#include <set>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<vector<short>> friendship(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    friendship[a].push_back(b);
    friendship[b].push_back(a);
  }

  set<short> attendee;
  for (auto dfriend : friendship[1]) {
    attendee.insert(dfriend);
    for (auto ffriend : friendship[dfriend]) {
      if (ffriend != 1) {
        attendee.insert(ffriend);
      }
    }
  }

  cout << attendee.size();
  return 0;
}
