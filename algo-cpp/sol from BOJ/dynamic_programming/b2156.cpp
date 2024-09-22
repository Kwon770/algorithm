// https://www.acmicpc.net/problem/2156
// Dynamic Programming (10), 포도주 시식
// NUMBER 2156

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 2579 계단오르기와 방식이 거의 유사함
// 하지만 연속 3잔을 마실수 없다고만 조건을 세웠지, 몇 잔을 안마시면 안되는지를 명시하지 않음을 주목해야 함
// 계단오르기의 방식을 그대로 쓰면 100 400 2 1 4 200 의 경우, 두 번 연속으로 안마시는 반례가 있음

// 따라서 현재 단계에서 안마시는 경우를 추가해야하므로, (i - 1) 과 (i) 를 서로 비교도 해야함

#include <iostream>

using namespace std;
#define MAX 10001
int input[MAX], result[MAX];

void Solve(int n) {
    result[1] = input[1];
    result[2] = input[2] + input[1];
    for (int i = 3; i <= n; i++)
        result[i] = max(result[i - 1], max(result[i - 2] + input[i], result[i - 3] + input[i - 1] + input[i]));
    cout << result[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> input[i];
    Solve(N);
    return 0;
}