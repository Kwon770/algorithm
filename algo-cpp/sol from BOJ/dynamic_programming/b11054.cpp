// https://www.acmicpc.net/problem/11054
// Dynamic Programming (12), 가장 긴 바이토닉 부분 수열
// NUMBER 11054

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 11053, 가장 긴 증가하는 부분 수열과 접근 방식은 거의 유사함
// 바이토닉 수열은 증가하는 수열과 감소하는 수열이므로, 수열의 각 숫자의 증가하는 수열과 감소하는 수열의 값을 구하고
// 수열의 각 숫자가 가진 값을 더하였을 경우 최대값을 구하면 가장 긴 바이토닉 부분 수열의 길이임

// 단, 수열의 길이 값은 본인까지 포함임으로, 최종 길이를 출력할대 -1 해야함

#include <iostream>

using namespace std;
#define MAX 1001
int input[MAX], up[MAX], down[MAX];

void Solve(int n) {
    for (int i = 1; i <= n; i++) {
        for (int o = 1; o < i; o++) {
            if (input[o] < input[i])
                up[i] = max(up[i], up[o] + 1);
        }
    }

    for (int i = n; i > 0; i--) {
        for (int o = n; o > i; o--) {
            if (input[o] < input[i])
                down[i] = max(down[i], down[o] + 1);
        }
    }

    int maxVal = 0;
    for (int i = 1; i <= n; i++)
        maxVal = maxVal > up[i] + down[i] ? maxVal : up[i] + down[i];
    cout << maxVal - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> input[i];

    fill_n(up, N + 1, 1);
    fill_n(down, N + 1, 1);
    Solve(N);

    return 0;
}