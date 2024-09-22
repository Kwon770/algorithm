// https://www.acmicpc.net/problem/1934
// NUMBER 1934 최소공배수

// 최대공약수는 최대공약수로 도출할 수 있으며, 최대공약수는 유클리드 호재법으로 구할 수 있음
// 두 자연수 A,B의 최대공약수 G, 최소공배수 L이라 하면
// A * B = L * G => L = A * B / G 를 활용

// GCD LCM https://www.notion.so/sckwon770/d6959a453a644d6d96b0ba139d22a29a

#include <iostream>
using namespace std;

#define endl "\n"

int gcd(int _a, int _b)
{
    while (_b != 0)
    {
        int r = _a % _b;
        _a = _b;
        _b = r;
    }
    return _a;
}

int lcm(int _a, int _b)
{
    return _a * _b / gcd(_a, _b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b;

    cin >> t;
    while (t)
    {
        cin >> a >> b;

        cout << lcm(a, b) << endl;
        t--;
    }
    return 0;
}