// https://www.acmicpc.net/problem/15686
// 15686 치킨 배달
// Memory : 2020 KB
// Time : 0 ms
//
// 단순히 몇개의 A와 몇개의 B를 주어주고, A와 B간의 최소 거리를 구하는 문제가
// 아니라 주어진 B 중에서 최소가 될 수 있는 B를 뽑으라는 조건이 붙어서 더욱
// 복잡해졌다. 다만 A의 최대개수가 2N=100, B의 최대개수가 13이므로 크지 않아서
// 단순히 브루트포스로 풀 수 있는 문제였다. (A = 집, B = 치킨집)
// (prev_permutation을 통해 조합을 구함) 모든 치킨집에 대한 모든 집의 거리를
// 구하고, 가능한 치킨집의 테스트케이스를 조합으로 구하여 테스트케이스별
// 최소거리를 구했다.

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> houses, chickens;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int type;
      cin >> type;
      if (type == 1) {
        houses.push_back(make_pair(i, j));
      } else if (type == 2) {
        chickens.push_back(make_pair(i, j));
      }
    }
  }

  vector<vector<int>> chickenstreet(chickens.size(),
                                    vector<int>(houses.size(), 0));
  for (int i = 0; i < (int)chickens.size(); i++) {
    for (int j = 0; j < (int)houses.size(); j++) {
      int distance = abs(houses[j].first - chickens[i].first) +
                     abs(houses[j].second - chickens[i].second);
      chickenstreet[i][j] = distance;
    }
  }

  int minSum = INT_MAX;
  vector<bool> combination(chickens.size(), false);
  for (int i = 0; i < m; i++)
    combination[i] = true;
  do {
    vector<int> tempMinDistances(houses.size(), INT_MAX);
    for (int i = 0; i < (int)chickens.size(); i++) {
      if (combination[i]) {
        for (int j = 0; j < (int)chickenstreet[i].size(); j++) {
          tempMinDistances[j] = min(tempMinDistances[j], chickenstreet[i][j]);
        }
      }
    }

    int tempMinSum = 0;
    for (int tempMinDistance : tempMinDistances)
      tempMinSum += tempMinDistance;
    minSum = min(minSum, tempMinSum);
  } while (prev_permutation(combination.begin(), combination.end()));

  cout << minSum;
  return 0;
}
