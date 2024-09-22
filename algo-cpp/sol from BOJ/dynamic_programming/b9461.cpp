// https://www.acmicpc.net/problem/9461
// Dynamic Programming (4), 파도반 수열
// NUMBER 9461

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 수열의 규칙은 arr[i] = arr[i - 2] + arr[i - 3]을 가지고 있으므로
// 피보나치와 같이 값을 유지하는 동적계획법을 이용하여 품

#include <iostream>

using namespace std;
#define endl "\n"
#define MAX 101

long long arr[MAX];

long long Solve(int n) {
    for (int i = 4; i <= n; i++) {
        arr[i] = arr[i - 2] + arr[i - 3];
    }

    return arr[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    cin >> T;

    arr[1] = arr[2] = arr[3] = 1;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << Solve(N) << endl;
    }

    return 0;
}
