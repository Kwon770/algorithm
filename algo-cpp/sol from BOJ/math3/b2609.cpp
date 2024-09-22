// https://www.acmicpc.net/problem/2690
// math3 (4) 최공 최약
// NUMBER 2690

// Math Theorem, https://www.notion.so/sckwon770/Math-Theorem-6a3043ed872b41b88fbbafaddbde2fc2

// 유클리드 알고리즘 사용
// 1. 임의의 두 정수 a, b 입력
// 2. b 가 a 보다 크다면 a 와 b 값 교체
// 3. a 에다가 a - b 값 저장
// 4. a가 0 이면 b 가 최대 공약수, 아니면 2번으로 돌아가 반복

// while 이용해 a == 0 단순히 표현
// a - b 대신 a % b 로 효율 증가

// LCM 은 최소 공배수 GCD 는 최대 공약수
// A * B = L * G => L = A * B / G 를 활용

#include <iostream>
using namespace std;

#define endl "\n"

int GetLcm(int _gcd, int a, int b) {
    return a * b / _gcd;
}

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

    int a, b;
    cin >> a >> b;

    int gcd = GetGcd(a, b);
    cout << gcd << endl;
    cout << GetLcm(gcd, a, b) << endl;

    return 0;
}