// https://www.acmicpc.net/problem/5086
// math3 (1)
// NUMBER 5086

// Math Theorem, https://www.notion.so/sckwon770/Math-Theorem-6a3043ed872b41b88fbbafaddbde2fc2

// a 가 b 의 약수일 경우 - a % b = 0
// a 가 b 의 배수일 경우 - b & a = 0
// 두 경우 모두 아닐경우 - 배수와 약수의 관계가 아님

#include <iostream>
using namespace std;

#define endl "\n"

int a, b;
string result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;

        if (b % a == 0)
            result = "factor";
        else if (a % b == 0)
            result = "multiple";
        else
            result = "neither";

        cout << result << endl;
    }

    return 0;
}