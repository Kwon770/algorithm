// https://www.acmicpc.net/problem/11053
// Dynamic Programming (11), 가장 긴 증가하는 부분 수열
// NUMBER 11053
// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c
// 11053 Note, https://www.notion.so/sckwon770/11053-72665b21404f4711a5fbb121f8d220fb

// 수열 3 2 5 2 3 1 4
// 부분 수열 => 3, 2 5, 3 5 3 1
// 증가하는 부분 수열  => 2 5, 2 3 4
// 가장 긴 증가하는 부분 수열 => 2 3 4
// 부분 수열을 구할 때 수열의 순서를 지켜야 함

// 단순히 답을 구하는 것을 쉬울 수 있지만, 중복을 확인하기 위하여 많은 반복이 발생됨
// 시간을 생각하여 동적계획법을 사용할 경우, 중복을 계산하는 과정이 빠져 효율적임

// 각 자리 숫자의 증가하는 부분 수열을 저장
//  => 현재 기준의 숫자보다 대상의 숫자가 클 경우 (증가하는)
//    => 현재 기준의 부분 수열보다 대상 자리의 부분 수열 + 1 (더해졌을때의 부분 수열)이 클 경우
//    (이 부분을 통해 중복을 확인함) (크지 않다면 의미없는 수이거나, 이전 비교한 수와 같은 수)
// 이 수를 저장하며, 효율적인 최대값 계산을 위해 이 반복문 내에서 최대값을 저장함

#include <iostream>

using namespace std;
#define MAX 1001
int input[MAX], maxLen = 0;

void Solve(int n) {
    int result[n + 1];
    fill_n(result, n + 1, 1);
    for (int i = n; i > 0; i--) {
        for (int o = i; o <= n; o++) {
            if (input[i] < input[o])
                result[i] = max(result[i], result[o] + 1);
            maxLen = max(maxLen, result[i]);
        }
    }
    cout << maxLen << endl;
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