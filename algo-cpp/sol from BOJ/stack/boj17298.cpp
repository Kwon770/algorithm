// https://www.acmicpc.net/problem/17298
// 17298 오큰수
//
// 스택보단 벡터를 통해 각자리마다 그 자라의 오큰수를 찾는게 더 쉽고 충분해
// 보였다. 각 자라기준에서 오른쪽으로 확인할 것이고, 최악의 경우에나 N회이고
// 보통은 그보다 작을테니 충분하다 생각했지만 TLE다. 이 문제는 스택을 이용한
// 풀이가 필수적이다
#include <iostream>
#include <stack>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<int> v(n);
  stack<int> s;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    while (!s.empty() && v[s.top()] < v[i]) {
      ans[s.top()] = v[i];
      s.pop();
    }
    s.push(i);
  }

  for (auto t : ans)
    cout << t << " ";
  return 0;
}
