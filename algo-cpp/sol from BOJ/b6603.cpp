// https://www.acmicpc.net/problem/6603
// NUMBER 6603, 로또

#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define TARGET_NUM 6

int k;
vector<int> input, numbers;

void printNumbers() {
    for (int i = 0; i < TARGET_NUM; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

void getNumbers(int cnt, int idx) {
    if (TARGET_NUM - cnt > k - idx) {
        return;
    }

    if (cnt == TARGET_NUM) {  // cnt akso start counting from 0
        printNumbers();
        return;
    }

    for (int i = idx; i < k; i++) {
        numbers.push_back(input[i]);
        getNumbers(cnt + 1, i + 1);
        numbers.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int temp;
    while (true) {
        cin >> k;
        if (k == 0) break;
        input.clear();
        for (int i = 0; i < k; i++) {
            cin >> temp;
            input.push_back(temp);
        }

        getNumbers(0, 0);
        cout << endl;
    }

    return 0;
}