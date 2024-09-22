// https://www.acmicpc.net/problem/2579
// Dynamic Programming (7), 계단오르기
// NUMBER 2579

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

#include <iostream>

using namespace std;
#define MAX 301
int arr[MAX], N;

int Solve() {
    int total = arr[N];
    while (N > 0) {
        if (arr[N - 1] > arr[N - 2 < 0 ? 0 : N - 2]) {
            total += arr[N - 1];
            N -= 1;
            total += arr[N - 2 < 0 ? 0 : N - 2];
            N -= 2;
        } else {
            total += arr[N - 2];
            N -= 2;
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    arr[0] = 0;

    cout << Solve() << endl;

    return 0;
}