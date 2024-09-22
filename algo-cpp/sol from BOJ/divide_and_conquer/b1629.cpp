// https://www.acmicpc.net/problem/1629
// Divide_and_conquer(4), 곱셈
// NUMBER 1629

// Divide and Conquer, https://www.notion.so/sckwon770/Divide-and-conquer-568ac70283ce41b29a01c4e147f4830c

// 모듈러의 연산을 이용하여 for문 반복하는 코드를 작성하였으나, 시간초과
// (모듈러의 연산을 통해 연산할 숫자가 낮으면 연산시간이 개선될거라 생각함)
// (숫자의 크기는 메모리쪽, 시간의 복잡도에서도 이는 고려하는 사항이 아님)

// 시간 제한을 위해서는 분할정복을 통해 연산의 양을 줄여야함.
// 제곱의 특성상 제곱의 숫자끼리 곱하여 제곱의 수를 연산함을 이용 (ex. 2^2 * 2^2 = 2^4)

// 그저 연산의 양을 줄인 후 계산하면 오버플로우가 발생하므로 모듈러의 연산을 사용함.
// 다만 재귀함수 속 모듈러 연산이므로 아래 링크를 참고해야 한다.
// https://www.notion.so/sckwon770/Modular-Arithmetic-dd1d2dcb4a4d439b8216809409851579#fd7c277414274295a12a579d1cec8d33
// 모듈러의 연산을 하기 전의 계산에서 오버플로우를 막기위해 long long 을 사용함.

#include <iostream>
using namespace std;
#define endl '\n'

long long pow(int a, int b, int c) {
    if (b == 1)
        return a;
    else {
        long long temp = pow(a, b / 2, c);
        if (b % 2)
            return ((temp * temp) % c * a) % c;
        else
            return (temp * temp) % c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    cout << pow(a % c, b, c) << endl;
    return 0;
}