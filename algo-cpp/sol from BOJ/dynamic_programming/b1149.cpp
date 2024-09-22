// https://www.acmicpc.net/problem/1149
// Dynamic Programming (5), RGB거리
// NUMBER 1149

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 단순히 생각하면 Backtracking 이 떠오지만, .5초의 제한이 있으므로 최대한 효율적으로 풀어야 함
// 선택에 따른 합의 비교를 입력단과 이전 입력단의 합으로만 비교할 경우, 다음과 같은 경우에 오류가 발생
// 22 18 20
// 15 20 20
// 10 20 20

// 때문에 이전 단계의 값을 유지하되, 입력값 아닌 합계를 저장함으로서 현재 입력단의 r g b 모든 경우와
// 이전 단계에서 최소값으로 합해진 r g b 모두를 확인할 수 있음

#include <iostream>

using namespace std;

void Solve(int N) {
    int r, g, b, cache[3], rgb[3];
    cin >> r >> g >> b;
    rgb[0] = r, rgb[1] = g, rgb[2] = b;

    for (int i = 1; i < N; i++) {
        for (int o = 0; o < 3; o++)
            cache[o] = rgb[o];

        cin >> r >> g >> b;
        rgb[0] = r + min(cache[1], cache[2]);
        rgb[1] = g + min(cache[0], cache[2]);
        rgb[2] = b + min(cache[0], cache[1]);
    }

    cout << min(min(rgb[0], rgb[1]), rgb[2]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    Solve(N);
    return 0;
}