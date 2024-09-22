// https://www.acmicpc.net/problem/2579
// Dynamic Programming (7), 계단오르기
// NUMBER 2579

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 접근방식은 1149-RGB거리, 1932-정수삼각형과 비슷한 동적계획법 방식이다
// 주어진 N개의 수를 차례대로 계산하면서 각 수가 선택될 때의 최대의 값을 계산한다

// 각 경우가 최대값이 되기 위해선, 두가지의 경우가 있는데, N번째에서
// (1) N - 2(이 곳까지 쭉이어 진 경우이므로, 총합) 와 N 이 선택될 경우
// (2) N - 3(이 곳까지 쭉이어 진 경우이므로, 총합) 와 N - 1 와 N 이 선택될 경우 => 연속된 3개가 선택되면 안되므로
// 각 경우 중 최대값을 판별하여 계산

#include <iostream>

using namespace std;
#define MAX 300
int arr[MAX], value[MAX], N;

int Solve() {
    value[0] = arr[0];
    value[1] = arr[0] + arr[1];
    value[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
    for (int i = 3; i < N; i++) {
        value[i] = max(arr[i] + value[i - 2], arr[i] + arr[i - 1] + value[i - 3]);
        value[i] = max(value[i], value[i - 3] + input[i]);
    }

    return value[N - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << Solve() << endl;

    return 0;
}