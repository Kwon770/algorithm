// https://www.acmicpc.net/problem/19639
// 19639 배틀로얄
//
// 단순한 그리디 문제이지만, 두 가지를 조심해야 한다.
// 1. 체력회복은 1회만으로 충분하지 않을 수 있다.
// 체력회복양이 적어서 한 명을 처치 후 아이템을 여러 개 먹어야되는 경우가 있다.
// 2. 적을 모두 처지해야하며 "아이템을 모두 소비해야 한다"
// 적을 모두 처지하는 것은 상식이지만 아이템의 경우는 당연히 필요한 만큼만
// 써야한다 생각해서 조건을 보지 않으면 맞왜틀에 빠진다.
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define endl '\n'
using namespace std;

struct {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    return a.first > b.first;
  }
} Cmp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int x, y, m, inp;
  cin >> x >> y >> m;
  vector<pair<int, int>> damage;
  vector<pair<int, int>> item;
  for (int i = 1; i <= x; i++) {
    cin >> inp;
    damage.push_back(make_pair(inp, i));
  }
  sort(damage.begin(), damage.end(), Cmp);
  for (int i = 1; i <= y; i++) {
    cin >> inp;
    item.push_back(make_pair(inp, i));
  }
  sort(item.begin(), item.end(), Cmp);

  vector<int> order;
  int health = m;
  auto itemIter = item.begin();
  for (auto damageIter = damage.begin(); damageIter != damage.end();
       damageIter++) {
    health -= (*damageIter).first;
    if (health <= 0) {
      cout << 0;
      return 0;
    }

    order.push_back(-1 * (*damageIter).second);
    while (itemIter != item.end() && m - health >= (*itemIter).first) {
      health += (*itemIter).first;
      order.push_back((*itemIter).second);
      itemIter++;
    }
  }

  while (itemIter != item.end()) {
    order.push_back((*itemIter).second);
    itemIter++;
  }

  for (int o : order)
    cout << o << endl;
  return 0;
}
