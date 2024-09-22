// https://www.acmicpc.net/problem/11057
// 11057 오르막 수
//
// 평범한 DP와는 캐싱 방법이 다르다.
// 아무 생각없이 모든 수를 캐싱하려하면 메모리초과가 날 것이다.
// 이 문제는 최대 1000개 자리 숫자에 대한 오르막 수를 구하도록 하고 있기 때문에
// 그 모든수를 캐싱하기 위한 배열을 만들면 당연히 메모리 초과가 난다.
//
// 때문에 캐싱 방법에 대한 아이디어를 떠올리는게 핵심인데,
// n자리의 오르막 수를 구하기 위해서는 n - 1자리의 숫자들의 오르막 수들의 마지막
// 숫자만 확인하면 된다는 사실을 이용하면 된다. 마지막 자리 숫자만 확인하면
// 오르막 수들은 앞의 숫자들은 오르막이라는 것을 보장하기 때문이다. 따라서
// 마지막 숫자별 갯수를 캐싱하면 된다.
//
// 이를 이용한 풀이에서 반복문에 최적화를 한번 더 할 수 있는데,
// n개 자리의 k로 끝나는 오르막 수는 n - 1개 자리의 k보다 작은 수들로 끝나는
// 오르막 수를 더하면 되므로 k를 0부터 시작하여 8까지 더하면서 진행하면 반복문이
// 단순해진다. (17번줄)
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

#define MOD 10007
vector<int> cache(10, 1);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 8; j++) {
      cache[j + 1] += cache[j] % MOD;
    }
  }

  int sum = 0;
  for (int i = 0; i < 10; i++)
    sum += cache[i] % MOD;
  cout << sum % MOD;

  return 0;
}
