// https://www.acmicpc.net/problem/5585
// NUMBER 5585, 거스름돈

// Simple Greedy Algorithm

#include <iostream>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int money[] = {500, 100, 50, 10, 5, 1};
    int exchange = 1000;
    int price;
    int cnt = 0;
    int idx = 0;

    cin >> price;
    exchange -= price;
    while (exchange != 0) {
        int tmp = exchange / money[idx];
        cnt += tmp;
        exchange -= money[idx] * tmp;
        idx++;
    }
    cout << cnt << endl;
    return 0;
}