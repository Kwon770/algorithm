// https://www.acmicpc.net/problem/1463
// Dynamic Programming (8), 1로 만들기
// NUMBER 1463

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

// 1 ~ N - 1 까지의 깂을 구하며, 이 값들을 이용해서 N 구함
// i 의 값을 구할 때, (i - 1) (i / 2) (i / 3) 값 중 최소의 값을 이해야 하므로,
// min 을 통해서 검사하며, (i / 2) (i / 3) 은 i가 나눠질때만 사용가능한 조건을 꼭 확인해야함

#include <iostream>

using namespace std;
int arr[1000001];

int Solve(int n) {
    arr[1] = 0;
    arr[2] = arr[3] = 1;
    for (int i = 4; i <= n; i++) {
        arr[i] = arr[i - 1] + 1;
        if (!(i % 2))
            arr[i] = min(arr[i], arr[i / 2] + 1);
        if (!(i % 3))
            arr[i] = min(arr[i], arr[i / 3] + 1);
    }
    return arr[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << Solve(n) << endl;

    return 0;
}