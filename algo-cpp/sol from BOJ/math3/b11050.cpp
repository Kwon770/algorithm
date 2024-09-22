// https://www.acmicpc.net/problem/11050
// math3 (7) 이항 계수
// NUMBER 11050

// Math Theorem, https://www.notion.so/sckwon770/Math-Theorem-6a3043ed872b41b88fbbafaddbde2fc2

// 이항 계수 (N k) = nCk = N! / (N - K)!K! 공식 이용
// 팩토리얼은 재귀함수를 이용하되, 0! = 1 인 경우를 처리해야함

#include <iostream>
using namespace std;

#define endl "\n"

int factor(int i) {
    if (i == 0)
        return 1;

    if (i == 1)
        return i;
    else
        return i * factor(i - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    cout << factor(n) / (factor(n - k) * factor(k)) << endl;

    return 0;
}