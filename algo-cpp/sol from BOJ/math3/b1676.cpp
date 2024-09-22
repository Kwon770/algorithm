// https://www.acmicpc.net/problem/1676
// math3(10), 팩토리얼 0의 개수
// NUMBER 1676

// Math Theorem, https://www.notion.so/sckwon770/Math-Theorem-6a3043ed872b41b88fbbafaddbde2fc2

// 마지막 자리쪽에 0이 존재할려면 2 와 5의 곱이 생겨야 한다.
// 이는 소인수분해의 결과에서 2와 5의 존재를 통해 확인할 수 있다는 것이 핵심

// 숫자내에서 2는 무조건 충분하므로, 5의 존재가 0의 개수에 영향을 미침
// 팩토리얼을 순회하면서 각 숫자의 5의 개수를 확인 > 각 수의 소인수분해로 5의 개수를 확인

#include <cmath>
#include <iostream>
using namespace std;
#define endl '\n'

int fac(int n) {
    if (n == 1)
        return 1;
    return n * fac(n - 1);
}

int prim(int n) {
    int cnt = 0;
    while (n % 5 == 0) {
        n /= 5;
        cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (i % 5 == 0)
            cnt += prim(i);

    cout << cnt << endl;
    return 0;
}