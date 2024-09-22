// https://www.acmicpc.net/problem/11727
// NUMBER 11727 2Xn 타일링2

// 점화식을 만들어낸다면 간단히 dp로 구현가능한 문제이다.
// 11726, 2Xn 타일링 문제에서, 2x2 블럭이 추가되었으므로, 점화식을 약간 수정해야 한다.
// i번째의 경우, (i-1)은 1x2 블럭 하나가 추가될 수 있으며 (i-2)은 2x1, 2x2 가 추가 될 수 있다. 따라서
//  => i = (i - 1) + (i - 2) * 2 의 점화식이 성립된다.

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
    square[2] = 3;
    for (int i = 3; i <= n; i++) square[i] = (square[i - 2] * 2 + square[i - 1]) % MOD;
    cout << square[n] << endl;
    return 0;
}