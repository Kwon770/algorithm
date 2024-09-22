// https://www.acmicpc.net/problem/1935
// 1935 후위표기식2
// Memory : 2024 KB , Time : 0 ms
//
// 피연산자가 변수처럼 쓰이는 후위표기식을 계산하는 문제라 크게 어렵지 않다.
// 후위표기식을 스택으로 계산하고, Char을 이용하여 변수를 올바르게 치환한 다는 것을 깨달으면 된다.
// cout 의 소수 출력 fixed, precision과 소수점에서 버림하기를 몰라서 이 부분이 시간이 조금 걸렸다

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int N;
string expression;
vector<double> numbers;
stack<double> calculation;

double calculate(double a, double b, char type) {
    if (type == '+') {
        return a + b;
    } else if (type == '-') {
        return a - b;
    } else if (type == '*') {
        return a * b;
    } else {
        return a / b;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> expression;
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    for (char e : expression) {
        if ('A' <= e && e <= 'Z') {
            calculation.push(numbers[e - 'A']);
        } else {
            double b = calculation.top();
            calculation.pop();
            double a = calculation.top();
            calculation.pop();

            double result = calculate(a, b, e);
            calculation.push(result);
        }
    }

    double ans = calculation.top();
    ans = (floor(ans * 100)) / 100;
    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}