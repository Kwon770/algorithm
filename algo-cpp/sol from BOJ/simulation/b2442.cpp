// https://www.acmicpc.net/problem/2442
// 2442 별 찍기 - 5
//
// 피라미드 오른편은 공백 없음.
#include <iostream>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  int line = 2 * n - 1;
  for (int i = 1; i <= n; i++) {
    int star = 2 * i - 1;
    for (int j = 1; j <= (line - star) / 2; j++)
      cout << " ";
    for (int j = 1; j <= star; j++)
      cout << "*";
    cout << endl;
  }

  return 0;
}
