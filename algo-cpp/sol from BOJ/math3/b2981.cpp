// https://www.acmicpc.net/problem/2981
// 2981 검문
//
// 풀이, https://www.notion.so/sckwon770/2981-ce8b5cd75584435da59fe533c23d07a2
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());
  int val = nums[1] - nums[0];
  for (int i = 2; i < n; i++) {
    val = gcd(val, nums[i] - nums[i - 1]);
  }

  set<int> ans;
  for (int i = 2; i * i <= val; i++) {
    if (val % i == 0) {
      ans.insert(i);
      ans.insert(val / i);
    }
  }
  ans.insert(val);

  for (int a : ans)
    cout << a << " ";
  return 0;
}
