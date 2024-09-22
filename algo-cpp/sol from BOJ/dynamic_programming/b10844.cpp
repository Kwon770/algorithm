// https://www.acmicpc.net/problem/10844
// Dynamic Programming (9), 쉬운 계단 수
// NUMBER 10844

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 1 2 3 4 5 6 7 8 9
// 10 11 21 22 32 34 ...

// 계단수는 급접한 두 숫자이므로, 0 과 9 를 제외하곤 2개를 가진다는 특징이 있다.
// 이를 이용하여 이전 단계의 계단 수를 이용하여 현재 단계의 계단 수를 구함

// value[N][P]는 길이가 N일때, 마지막 숫자가 P 일때의 경우의 수라라고 할때,
// 마지막 숫자를 기준으로 하면, 그 앞의 숫자들은 N - 1인 계단 수를 통해 구할 수 있을 것이고
// (N - 1 계단수) + (N 의 마지막 수) 가 되기 위핵선 (N - 1 계단수) 의 마지막 숫자가 조건에 만족하면 됨
// value[N][P] = value[N - 1][P - 1] + value[N - 1][P + 1]

// 오버플로우를 방지하기 위해 모듈러의 연산을 사용

#include <iostream>

using namespace std;
#define MAX 101
#define DIV 1000000000
int value[MAX][11];

void Solve(int n) {
    for (int i = 1; i <= 9; i++)
        value[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        value[i][0] = value[i - 1][1];
        for (int o = 1; o <= 9; o++) {
            value[i][o] = (value[i - 1][o - 1] + value[i - 1][o + 1]) % DIV;
        }
    }

    long long sum = 0;
    for (int i = 0; i < 10; i++)
        sum += value[n][i];
    cout << sum % DIV << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    Solve(n);
    return 0;
}