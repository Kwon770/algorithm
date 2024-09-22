// https://www.acmicpc.net/problem/16953
// NUMBER 16953

#include <iostream>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, cnt = 0;
    cin >> a >> b;
    while (true) {
        if (b == a) {
            break;
        } else if (b < a) {
            cnt = -2;
            break;
        } else {
            if (b % 2 == 0) {
                b /= 2;
            } else if (b % 10 != 1) {
                cnt = -2;
                break;
            } else {
                b /= 10;
            }
            cnt++;
        }
    }
    cout << cnt + 1 << endl;
    return 0;
}