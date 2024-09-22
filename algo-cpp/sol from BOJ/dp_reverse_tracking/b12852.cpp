// https://www.acmicpc.net/problem/12852
// DP and Shortest path reverse tracking(1), 12852 1로 만들기

// 최적해를 구하며, 그 스텝 또한 출력해야하는 문제이다.

// 바텀업 방식으로 접근하였다.
// 1에서 시작하여 N - 1 까지 올라가면서 (i * 3), (i * 2), (i + 1) 지점에 최적 횟수를 갱신해나가면 된다.
// N -1 까지 갱신하는 단계를 거쳤다면 V부터 1이 될때까지 내려가면서 스탭을 출력하면 된다.
// 각 스텝에서 최적해를 구하기 위해 저장한 최적해 배열과 스탭을 저장하기 위한 이전 스탭 인덱스 배열을 이용한다.

// e.g) N = 10 => before = [0, 0, 1, 1, 2, 4, 2, 6, 4, 3, 9]

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int values[1000001];
    int prev[1000001];
    memset(values, 0x3f, sizeof(values));
    values[1] = 0;
    for (int i = 1; i < n; i++) {
        if (i * 3 <= n && values[i * 3] > values[i] + 1) {
            prev[i * 3] = i;
            values[i * 3] = values[i] + 1;
        }
        if (i * 2 <= n && values[i * 2] > values[i] + 1) {
            prev[i * 2] = i;
            values[i * 2] = values[i] + 1;
        }
        if (i + 1 <= n && values[i + 1] > values[i] + 1) {
            prev[i + 1] = i;
            values[i + 1] = values[i] + 1;
        }
    }

    cout << values[n] << endl;
    cout << n << " ";
    while (prev[n] != 0) {
        cout << prev[n] << " ";
        n = prev[n];
    }

    return 0;
}