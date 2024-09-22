// https://www.acmicpc.net/problem/16500
// 16500 문자열 판별
//
// 어떤 식으로 캐싱하는지에 집중하게 되면 못풀게되는 문제이다.
// 부분 문자열은 다양하게 생성될 수 있고, 부분 문자열끼리 어떻게 조합될지도
// 다양한 예외를 낳기 때문에 그런 식의 캐싱으로는 풀기 힘들다.
//
// 이 문제에서는 문자열을 한 번 순회하면서, 이전의 문자들과 주어진 단어들을
// 조합하여, 현재 인덱스까지는 문자가 생성 가능한지를 캐싱한다. 각 인덱스의
// 캐싱이 true일 경우, 그 인덱스까지의 단어는 생성이 가능하다는 뜻이므로 가능한
// 순회이다.
//
// dp 문제에서 대략적으로 크게 분류하면
// 1. 비교, 확인 등의 대상이 되는 모든 경우의 수를 캐싱하거나 다양한 캐싱을 통해
// 조합해가는 문제
// 2. 캐싱은 보조의 역할이며 문제를 작게 나누는 것이 핵심이고, 이 과정에서
// 일일이 수행하는 문제 로 나뉠수 있다고 생각한다.
//
// 주어진 시간이 짧은데 반해 대상의 범위가 큰 경우 1번 유형이라고 가정하고 풀 수
// 있으며 이 문제처럼 2초정도 비교적 길고 범위가 100과 같이 작은 경우, 1번
// 유형일 수 도 있지만 2번일수도 있다는 것을 간과하면 안될 것 같다.
//
#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

vector<string> word;

bool checkVaild(string tar) {
  if (find(word.begin(), word.end(), tar) != word.end())
    return true;
  else
    return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  cin >> str;
  vector<bool> cache(str.length(), false);
  int n;
  cin >> n;
  word.resize(n);
  for (int i = 0; i < n; i++)
    cin >> word[i];

  for (int i = 0; i < (int)str.length(); i++) {
    string originalStr = str.substr(0, i + 1);
    cache[i] = checkVaild(originalStr);

    for (int j = 0; j < i; j++) {
      if (cache[i])
        break;
      if (!cache[j])
        continue;

      string neededStr = str.substr(j + 1, i - j);
      cache[i] = checkVaild(neededStr);
    }
  }

  if (cache[str.length() - 1])
    cout << 1;
  else
    cout << 0;
  return 0;
}
