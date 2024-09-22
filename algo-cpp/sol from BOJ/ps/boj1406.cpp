// https://www.acmicpc.net/status?user_id=sketom&problem_id=1406&from_mine=1
// 1406 에디터

// 문자열 조작이지만, insert erase를 계속해줘야되기 때문에 단순히 string을
// 사용하면 시간초과가 난다. erase, insert를 써도 시간복잡도가 적은 것은
// linkedlist로 구현된 stl의 list이다. 이를 이용하면 쉽게 구현할 수 있다. 한
// 가지 주의할 점은
// 1. 다른 STL Container와 다르게 insert erase를 해도 iterator나 reference가
// 무효화되지 않는다.
// 2. 단, erase시 지워지는 대상의 iterator와 reference는 무효화되기 때문에
// 주의해야 한다. 2번 때문에 SegFault 런타임에러가 떴었다.
#include <iostream>
#include <list>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  list<char> editor;
  string init;
  cin >> init;
  for (char c : init)
    editor.push_back(c);

  int m;
  cin >> m;
  auto iter = editor.end();
  rep(i, m) {
    char cmd, ipt;
    cin >> cmd;
    if (cmd == 'P')
      cin >> ipt;

    switch (cmd) {
    case 'L':
      if (iter == editor.begin())
        break;

      iter--;
      break;
    case 'D':
      if (iter == editor.end())
        break;

      iter++;
      break;
    case 'B': {
      if (iter == editor.begin())
        break;

      auto tmpIter = iter;
      editor.erase(--tmpIter);
      break;
    }
    case 'P':
      editor.insert(iter, ipt);
      break;
    }

    cout << *iter << endl;
    for (char c : editor) {
      cout << c;
    }
    cout << endl;
  }

  for (char c : editor) {
    cout << c;
  }
  return 0;
}
