// https://www.acmicpc.net/problem/설탕 배달
// NUMBER 2839, 설탕 배달

// Simple Dp

#include <iostream>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int five = 0;
    int three = 0;
    int weight, result;

    cin >> weight;
    result = weight;
    five = result / 5 + 1;

    while (result != 0) {
        five--;
        if (five == -1) {
            cout << -1 << endl;
            return 0;
        }

        result = weight - (5 * five);

        three = result / 3;
        result %= 3;
    }

    cout << five + three << endl;
    return 0;
}