// https://www.acmicpc.net/problem/2748
// Dynamic Programming (1), 피보나치 수 2
// NUMBER 2748

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 피보나치 수의 성질을 이용하며,
// 단순 재귀는 중복 연산으로 인한 성능저하때문에 값을 저장하며 동적계획법을 이용하며

// Pibo(0) = 0 / Pino(1) = 1 / Pino(n) = Pibo(n - 1) + Pibo(n - 2)

#include <iostream>

using namespace std;
#define endl "\n"
#define MAX 91

long long pibo[MAX], N;

long long Solve(int n) {
    for (int i = 2; i <= n; i++) {
        pibo[i] = pibo[i - 1] + pibo[i - 2];
    }
    return pibo[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if (N == 0)
        cout << 0;
    if (N == 1)
        cout << 1;
    else {
        pibo[0] = 0;
        pibo[1] = 1;
        cout << Solve(N);
    }

    return 0;
}
