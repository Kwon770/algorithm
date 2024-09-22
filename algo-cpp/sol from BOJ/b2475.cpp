#include <iostream>
#define endl "\n"
using namespace std;

int main() {
    int temp, total = 0;
    for (int i = 0; i < 5; i++) {
        cin >> temp;
        total += temp * temp;
    }
    cout << total % 10 << endl;
    return 0;
}