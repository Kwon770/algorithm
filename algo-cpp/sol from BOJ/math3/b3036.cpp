// https://www.acmicpc.net/problem/3036
// math3 (6) 링
// NUMBER 3036

// Math Theorem, https://www.notion.so/sckwon770/Math-Theorem-6a3043ed872b41b88fbbafaddbde2fc2

// 반지름이 다른 원간의 바퀴 비율을 a/b로 나타낸 식을 다음과 같이 표현할 수 있음
// pai*R(a)^2 : pai*R(b)^2 = lap(a) : lap(b)
//  => R(a) / R(b) = lap(a) / lap(b)
//  => R(a) / R(b) 를 기약분수로 바꾸기 위해 각 반지름에 최대공약수를 나눔.

#include <iostream>
using namespace std;

#define endl "\n"

int GetGcd(int a, int b) {
    int t;
    while (b) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 1; i < n; i++) {
        int gcd = GetGcd(arr[0], arr[i]);
        cout << arr[0] / gcd << '/' << arr[i] / gcd << endl;
    }

    return 0;
}