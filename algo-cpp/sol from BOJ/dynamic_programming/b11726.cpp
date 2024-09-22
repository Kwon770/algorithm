// https://www.acmicpc.net/problem/11726
// NUMBER 11726, 2 x N 타일링

// 블럭의 배치 방향에 따른 경우의 수
// 틀의 높이는 2로 고정이므로, 너비만 고려하여야하므로, 1블럭 2블럭 - 2가지 경우만 생각한다.
// i번째의 경우, (i-1)은 1x2 블럭 하나가 추가될 수 있으며 (i-2)은 2x1가 하나 추가 될 수 있다. 따라서
//  => i = (i - 1) + (i - 2) 의 점화식이 성립된다.

#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;
#define MOD 10007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int square[1001], n;
    cin >> n;
    square[1] = 1;
    square[2] = 2;
    for (int i = 3; i <= n; i++) square[i] = (square[i - 2] + square[i - 1]) % MOD;
    cout << square[n] << endl;
    return 0;
}