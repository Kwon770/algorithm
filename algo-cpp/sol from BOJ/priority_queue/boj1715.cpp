// https://www.acmicpc.net/problem/1715
// 1715 카드 정렬하기
//
// 문제의 진짜 의미를 파악하지 못해서 처음 주어진 숫자들 기준으로 작은 순으로
// 계산을 수행해서 많이 틀렸다. 문제의 진짜 의미를 파악하기 위해서는 10을 10번
// 주어주는 예시를 실행해보면 되는데, 이미 계산된(합쳐진) 카드묶음도 다시
// 계산되므로 헙쳐진 카드 묶음 또한 우선순위큐에 넣어서 작은 순으로 연산해야
// 한다.
#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

#define For(i, j, k) for (int i = j; i < (int)(k); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  priority_queue<int, vector<int>, greater<int>> pq;
  int n;
  cin >> n;
  For(i, 0, n) {
    int inp;
    cin >> inp;
    pq.push(inp);
  }

  long long ans = 0;
  while (!pq.empty() && pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    long long sum = a + b;
    ans += sum;

    if (!pq.empty())
      pq.push(sum);
  }
  cout << ans;

  return 0;
}
