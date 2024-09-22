// https://www.acmicpc.net/problem/1904
// Dynamic Programming (3), 01타일
// NUMBER 1904

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 문제의 핵심은 피보나치와 같이 arr[i] = arr[i - 1] + arr[i - 2] 이다
// N의 최댓값은 1000000 이므로, 오버플로우 방지를 위해 모듈러의 연산을 사용하여 푼다.

#include <iostream>

using namespace std;
#define endl "\n"
#define MAX 1000001
#define DIV 15746

int arr[MAX];

void Solve(int n) {
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    for (int i = 4; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % DIV;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    Solve(N);
    cout << arr[N] << endl;

    return 0;
}
