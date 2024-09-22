// https://www.acmicpc.net/problem/1449
// 1449 수리공 항승
//
// 별도의 처리없이 주어진 구멍을 순회하면서 테이프를 붙일지 안붙일지 바로바로
// 판단하면 되기 때문에 그리디로 풀 수 있다. 이진탐색을 사용하면 더 쉽게 풀 수
// 있지만 그리디를 공부중이므로 그리드식 풀이를 작성하였다.
//
// 핵심 원리는 구멍 하나에 한 테이프를 붙이느냐, 2개 이상에 붙이느냐를 구별하는
// 것인데, 2개 이상의 경우 제일 왼쪽 제일 오른쪽에 조건에 따라 0.5 만큼의 여유가
// 필요하므로 데이프 길이 - 1 만큼의 거리인지만 판단하면 된다.
//
// 이후 테이프가 2 이상이여서 구멍 여러 개에 테이프 하나가 가능할 경우에 판단
// 방법인데, 나는 별도의 반복문이 들어가지 않고 순회하면서 바로 판단하도록
// 짜고싶어서 현재 구멍과 다음 구멍간의 거리를 판단하였고, 한 테이프로 가능한
// 여지가 있으면 check 변수를 통해 코드의 분기를 뒀다. 구멍이 더 이상 이어지지
// 못한다고 판단된 마지막 구멍에서 갯수를 세어준다. 마지막 구멍에서 갯수를
// 세어야 24번과 같이 마지막 구멍에서의 예외처리가 깔끔하게 가능하다. (end() -
// 1이 마지막이므로 무조건 탈출할때 무조건 갯수를 더하면 됨)
//
#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, l;
  cin >> n >> l;
  vector<int> crack(n);
  for (int i = 0; i < n; i++) {
    cin >> crack[i];
  }

  sort(crack.begin(), crack.end());
  int ans = 0;
  bool check = false;
  int unitDist = 0;
  for (auto iter = crack.begin(); iter != crack.end(); iter++) {
    if (iter == crack.end() - 1) {
      ans++;
      break;
    }

    int curDist = *(iter + 1) - *iter;
    if (check) {
      unitDist += curDist;
      if (unitDist > l - 1) {
        check = false;
        ans++;
      }
    } else {
      if (curDist <= l - 1) {
        check = true;
        unitDist = curDist;
      } else {
        ans++;
      }
    }
  }

  cout << ans;
  return 0;
}
