// https://www.acmicpc.net/problem/11726
// NUMBER 11726, 2 x N 타일링

// 블럭의 배치 방향에 따른 경우의 수
// 틀의 높이는 2로 고정이므로, 너비만 고려하여야하므로, 1블럭 2블럭 - 2가지 경우만 생각한다.
// 즉, 1과 2로 된 순열을 만들며, 그 순열의 수의 합이 너비가 되는 것을 만족한다.

// 이 순열은 1로만 이루어진 순열을 초기 값으로 하며 (1로만 이루어진 순열은 무조건 존재하므로)
// 1블록 2개를 줄이고, 2블록 1개를 늘리는 식으로, 1블럭의 수가 0보다 작아지기 전까지 반복한다.

// 그리고 그 순열들의 경우의 수는 중복순열의 경우의 수/이항계수를 통해 계산하다.

// * 다만 c++은 팩토리얼 계산하는 단계에서 오버플로우로 인한 Integer division by zero 로 인해서, 런타임에러가 뜬다.
// 파이썬으로 시도해야함.

#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;
#define MOD 10007

int calculate(int f, int t) {
    int ans = 1;
    for (int i = f; i <= t; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int one = n, two = 0, cnt = 0;
    while (one >= 0) {
        int high = one < two ? two : one;
        int low = one < two ? one : two;
        cnt += (calculate(high + 1, one + two) / calculate(2, low)) % MOD;
        one -= 2;
        two += 1;
    }
    cout << cnt % MOD << endl;
    return 0;
}