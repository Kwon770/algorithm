// https://www.acmicpc.net/problem/1932
// Dynamic Programming (6), 정수 삼각형
// NUMBER 1932

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 기본적인 문제 아이디어는 1149번과 같다
// 1149번과 같이 이전 입력단 기준으로 합계를 관리하며 현재 입력단 기준으로 최대의 합계를 구함
// https://github.com/Kwon770/Baekjoon/blob/master/Dynamic%20Programming/b1149.cpp

// 일정한 개수로 입력되지 않으므로, o 번째 요소는 (o - 1) (o) 번째 이전요소와 더해질 수 있음을 고려하며
// (-1) (N + 1) 번째 요소의 문제를 해결해야 함 => arr[o - 1 < 0 ? 0 : o - 1] , MAX = MAX-N + 1

#include <iostream>

using namespace std;

#define MAX 501
int input, total[MAX], cache[MAX];

void Solve(int N) {
    cin >> cache[0];
    for (int i = 1; i < N; i++) {
        for (int o = 0; o < i; o++)
            total[o] = cache[o];

        for (int o = 0; o <= i; o++) {
            cin >> input;
            cache[o] = input + max(total[o - 1 < 0 ? 0 : o - 1], total[o]);
        }
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        if (max < cache[i])
            max = cache[i];
    }
    cout << max << endl;
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