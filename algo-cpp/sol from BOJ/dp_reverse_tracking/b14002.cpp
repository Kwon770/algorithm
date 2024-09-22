// https://www.acmicpc.net/problem/14002
// DP and Shortest path reverse tracking(2), 14002 가장 긴 증가하는 부분 수열 4

// 시간복잡도(N^2)를 요구하는 LIS 문제이므로, DP를 통해 풀면 된다.
// 출력에서 중가하는 부분 수열의 요소 출력을 요구하므로, 탑 다운 방식으로 풀면서
// 각 요소의 next 배열을 갱신한 후, 이를 통해 출력한다.

// !! 바텀탑 방식으로 풀면서 next 배열을 갱신하면 안된다. !!
// 계산을 위한 로직에서 하위 요소들이 비교를 위해서 끊임없이 next 배열이 갱신되므로, 잘못된 값이 들어가게 된다.

// !! 결과를 출력할 때 무조건 1번부터 출력을 하면 안된다. !!
// 1번이 무조건 부분 수열의 시작이 아니다.
// e.g. 3
//      3 1 2

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
    vector<int> inp(n + 1);
    vector<int> len(n + 1);
    vector<int> next(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> inp[i];
    }

    len[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (inp[j] > inp[i] && len[i] < len[j] + 1) {
                len[i] = len[j] + 1;
                next[i] = j;
            }
        }
        if (len[i] == 0) len[i] = 1;
    }

    int maxIdx = max_element(len.begin(), len.end()) - len.begin();
    cout << len[maxIdx] << endl;
    int idx = maxIdx;
    while (next[idx] != 0) {
        cout << inp[idx] << " ";
        idx = next[idx];
    }
    cout << inp[idx] << endl;

    return 0;
}