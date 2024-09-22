// https://www.acmicpc.net/problem/11050
// math3 (8) 이항 계수
// NUMBER 11050

// Math Theorem, https://www.notion.so/sckwon770/Math-Theorem-6a3043ed872b41b88fbbafaddbde2fc2
// 이항 계수 https://www.notion.so/sckwon770/c6476b1b276b4a8f86ad58caaff72181
// 동적 계획법  https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 동적계획법을 통한 풀이를 위해, 이항 계수의 성질을 이용하여 풀이
// (1) (N, K) = (N, N-K)
// (2) (N, K) = (N - 1, K) + (N - 1, K - 1)
// (3) (N, N) = (N, 0) = 1
// (4) (N, 1) = N

// 재귀를 통한 동적계획법 풀이를 단순 재귀과정으로 풀 경우, 중복되는 연산이 많아 성능 저하를 불러 일으키므로,
// 연산 결과를 저장하여 이항 계수를 푸는 방식을 적용

// 이항 계수를 구하는 과정에서 오버플로우를 방지하기 위해 모듈러 연산을 적용
// 문제가 요구하는 출력은 이항계수에서 10007를 나눈 나머지이므로, 구하는 과정에서 나머지를 이용하여 구함
// (a + b) % c = (a % c + b % c) % c

#include <iostream>
using namespace std;

#define endl "\n"
#define MAX 1001
#define DIVIDE 10007
int arr[MAX][MAX];

int Solve(int n, int k) {
    for (int i = 0; i <= n; i++) {
        arr[i][0] = arr[i][i] = 1;
        arr[i][1] = i;
    }

    for (int i = 3; i <= n; i++) {
        for (int o = 2; o <= k; o++) {
            arr[i][o] = (arr[i - 1][o] + arr[i - 1][o - 1]) % DIVIDE;
        }
    }

    return arr[n][k] % DIVIDE;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    cout << Solve(n, k) << endl;

    return 0;
}