// https://www.acmicpc.net/problem/1003
// Dynamic Programming (2), 피보나치 함수
// NUMBER 1003

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 피보나치 수는 1번째 피보나치 수의 호출을 통해 구하므로,
// N번째 피보나치 수 = N번째 피보나치 수가 1번째 피보나치 수를 호출한 횟수 = onePibo(N)
//   ==>  onePibo(N) = onePibo(N - 1) + onePibo(N - 2)

// 이와 비슷한 이유로 이전 피보나치 수를 통해 피보나치 수를 구하므로,
// N번째 피보나치 수가 0번째 피보나치 수를 호출한 횟수 = zeroPibo(N)
//   ==> zeroBipo(N) = zeroBipo(N - 1) + zeroBipo(N - 2)

// 단순 재귀함수의 비효율성떄문에 값을 저장하며 구한다.

#include <iostream>

using namespace std;
#define endl "\n"
#define MAX 41

long long zeroPibo[MAX], onePibo[MAX];
int T, N;

void Solve(int n) {
    for (int i = 2; i <= n; i++) {
        zeroPibo[i] = zeroPibo[i - 1] + zeroPibo[i - 2];
        onePibo[i] = onePibo[i - 1] + onePibo[i - 2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    zeroPibo[0] = 1;
    onePibo[0] = 0;
    zeroPibo[1] = 0;
    onePibo[1] = 1;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        Solve(N);
        cout << zeroPibo[N] << " " << onePibo[N] << endl;
    }

    return 0;
}
